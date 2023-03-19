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

	printf("%d", p->num );//先输出第一个数
	p = p->next;

	while (p != NULL)
	{
		printf("->%d",p->num);//格式输出
		p = p->next;
	}

	return NULL;
}



struct node* Exchange(struct node *head,int nub)
{
	if (nub % 2 != 0)//如果链表的数的个数为单数
	{
		nub--;
	}
	nub = nub / 2;//一共需要处理的次数
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
			break;//先判断，保护后面指针位置
		}
		p1 = p1->next;
		p1 = p1->next;//向下走两步
		p2 = p2->next;
		p2 = p2->next;//向下走两步

		
	}

	return NULL;
}

int main()
{
	int nub;
	printf("请输入你的需要保存的链表长度(大于等于1的数):\n");
	scanf_s("%d",&nub);
	struct node* head;
	head = Create(nub);

	printf("您保存的链表为:\n");
	Show(head);//显示链表

	Exchange(head,nub);//奇偶调换（最后如果多出一个则不处理）

	printf("\n单链表求调换后，链表为:\n");
	Show(head);//显示链表



	return 0;
}