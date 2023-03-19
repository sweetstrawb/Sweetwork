#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string>


using namespace std;

struct node
{
	int num;
	struct node* next;
};

struct node* Create(int nub)
{
	struct node* p1, * p2, * head;
	p1 = (struct node*)malloc(sizeof(node));
	p2 = (struct node*)malloc(sizeof(node));

	head = p1;

	int anum = 1;
	while (anum <= nub)
	{
		p1->num = anum;
		anum++;
		p2->next = p1;
		p2 = p1;
		p1 = p1->next;
		p1 = (struct node*)malloc(sizeof(node));
	}


	free(p1);
	p2->next = NULL;
	return head;
}

struct node* Show(struct node *head)
{
	struct node* p = head;

	printf("%d", p->num );//�������һ����
	p = p->next;

	while (p != NULL)
	{
		printf("->%d",p->num);//��ʽ���
		p = p->next;
	}

	return NULL;
}



struct node* Exchange(struct node *head,int nub)
{
	if (nub % 2 != 0)//�����������ĸ���Ϊ����
	{
		nub--;
	}
	nub = nub / 2;//һ����Ҫ����Ĵ���
	struct node* p1, * p2;
	p1 = head;
	p2 = head;
	p2 = p2->next;
	while (nub&&p1!=NULL&&p2!=NULL)
	{
		swap(p1->num, p2->num);
		nub--;
		if (nub <= 0)
		{
			break;//���жϣ���������ָ��λ��
		}
		p1 = p1->next;
		p1 = p1->next;//����������
		p2 = p2->next;
		p2 = p2->next;//����������

		
	}

	return NULL;
}

int main()
{
	int nub;
	printf("�����������Ҫ�����������(���ڵ���1����):\n");
	scanf_s("%d",&nub);
	struct node* head;
	head = Create(nub);

	printf("�����������Ϊ:\n");
	Show(head);//��ʾ����

	Exchange(head,nub);//��ż���������������һ���򲻴���

	printf("\n�����������������Ϊ:\n");
	Show(head);//��ʾ����



	return 0;
}