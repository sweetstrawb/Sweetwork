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

struct node* Create(int nub)//创建一个链表
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
	while (p3 != NULL)//p1,p2,p3分别相隔一个距离，p1最先指向空指针，然后p2指向p1，之后三个指针再向下移动一位
	{ 
		p2->next = p1;
		p1 = p2;
		p2 = p3;
		p3 = p3->next;
	}

	p2->next = p1;//p3到达空指针后，还差最后一次反转指向
	p1 = p2;

	return p2;
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

	struct node* Newhead;
	Newhead = Change(head);
	printf("\n反转之后的链表为:\n");
	Show(Newhead);//显示链表

	return 0;
}