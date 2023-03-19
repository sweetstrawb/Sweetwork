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

struct node *Link(int a,int b,struct node *head)
{
	struct node* p1, * p2;
	p1 = head;
	p2 = head;
	while (p1 != NULL)
	{
		if (p1->num == a)//Ѱ�ҽڵ�
		{
			break;
		}
		p1 = p1->next;
	}

	while (p2 != NULL)
	{
		if (p2->num == b)//Ѱ�ҽڵ�
		{
			break;
		}
		p2 = p2->next;
	}

	p1->next = p2;//���������ڵ�

	return NULL;
};

struct node *Judgew(struct node *head)
{
	struct node* p1, * p2;
	p1 = head;
	p2 = head;
	while (p2 != NULL)//p1�ٶ�Ϊ1��p2�ٶ�Ϊ2�����������׷����ɻ�
	{
		p1 = p1->next;
		p2 = p2->next;
		p2 = p2->next;
		if (p1 == p2)
		{
			printf("������ɻ�\n");
			return NULL;
		}
	}
	printf("�������ɻ�\n");

	return NULL;
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


	int frontnum,benum;
	printf("\n����������Ҫ���ӵ������ڵ�(��5 4���ո��������Ϊ5����4\n");
	scanf_s("%d%d", &frontnum, &benum);//�����û���Ҫ���ӵ������ڵ�
	Link(frontnum, benum,head);//���������ڵ�

	Judgew(head);



	return 0;
}