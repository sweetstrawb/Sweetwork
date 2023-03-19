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

	printf("%d", p->num);//先输出第一个数
	p = p->next;

	while (p != NULL)
	{
		printf("->%d", p->num);//格式输出
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
		if (p1->num == a)//寻找节点
		{
			break;
		}
		p1 = p1->next;
	}

	while (p2 != NULL)
	{
		if (p2->num == b)//寻找节点
		{
			break;
		}
		p2 = p2->next;
	}

	p1->next = p2;//连接两个节点

	return NULL;
};

struct node *Judgew(struct node *head)
{
	struct node* p1, * p2;
	p1 = head;
	p2 = head;
	while (p2 != NULL)//p1速度为1，p2速度为2，若两个最后追上则成环
	{
		p1 = p1->next;
		p2 = p2->next;
		p2 = p2->next;
		if (p1 == p2)
		{
			printf("该链表成环\n");
			return NULL;
		}
	}
	printf("该链表不成环\n");

	return NULL;
}


int main()
{
	int nub;
	printf("请输入你的需要保存的链表长度(大于等于1的数):\n");
	scanf_s("%d", &nub);
	struct node* head;
	head = Create(nub);

	printf("您保存的链表为:\n");
	Show(head);//显示链表


	int frontnum,benum;
	printf("\n请您输入需要连接的两个节点(如5 4，空格隔开，则为5连接4\n");
	scanf_s("%d%d", &frontnum, &benum);//读入用户需要连接的两个节点
	Link(frontnum, benum,head);//连接两个节点

	Judgew(head);



	return 0;
}