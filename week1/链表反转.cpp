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

struct node* Create(int nub)//����һ������
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



struct node* Show(struct node* head)
{
	struct node* p = head;

	printf("%d", p->num);//�������һ����
	p = p->next;

	while (p != NULL)
	{
		printf("->%d", p->num);//��ʽ���
		p = p->next;
	}

	return NULL;
}



struct node* Change(struct node* head)
{
	struct node* p1, * p2,*p3;
	p1 = head;
	p2 = head;
	p3 = head;
	p2 = p2->next;
	p3 = p3->next;
	p3 = p3->next;
	p1->next = NULL;
	while (p3 != NULL)//p1,p2,p3�ֱ����һ�����룬p1����ָ���ָ�룬Ȼ��p2ָ��p1��֮������ָ���������ƶ�һλ
	{ 
		p2->next = p1;
		p1 = p2;
		p2 = p3;
		p3 = p3->next;
	}

	p2->next = p1;//p3�����ָ��󣬻������һ�η�תָ��
	p1 = p2;

	return p2;
}

int main()
{
	int nub;
	printf("�����������Ҫ�����������(���ڵ���1����):\n");
	scanf_s("%d", &nub);
	struct node* head;
	head = Create(nub);

	printf("�����������Ϊ:\n");
	Show(head);//��ʾ����

	struct node* Newhead;
	Newhead = Change(head);
	printf("\n��ת֮�������Ϊ:\n");
	Show(Newhead);//��ʾ����

	return 0;
}