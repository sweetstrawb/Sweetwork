#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>

using namespace std;

struct node
{
	int num;
	struct node* next,*front;
};

struct node* Create()
{
	int innum;
	scanf_s("%d", &innum);//输入数据

	struct node* p1, * p2, * head;
	p1 = (struct node*)malloc(sizeof(node));
	p2 = (struct node*)malloc(sizeof(node));

	p1->front = NULL;//定义头节点的前一节点为空指针
	head = p1;

	while (innum >= 0)
	{
		p1->num = innum;//保存所输入的数据
		p2->next = p1;
		p2 = p1;

		p1 = p1->next;//节点移动
		scanf_s("%d", &innum);
		p1 = (struct node*)malloc(sizeof(node));
	}
	free(p1);//清除空间
	p2->next = NULL;//保证下面查看数据不报错
	return head;
}

struct node *twoCreate(struct node *head)
{
	struct node* p1, * p2;
	p1 = head;
	p2 = head;//第二个节点连接上面的节点
	p2 = p2->next;

	while (p2 != NULL)
	{
		p2->front = p1;//后一个节点指向前一个节点
		p2 = p2->next;//节点向下移动
		p1 = p1->next;//节点向下移动
	}

	return p1;
}


struct node* Show(struct node* head)
{
	struct node* p = head;
	while (p != NULL)
	{
		printf("%d ", p->num);//打印输出数据
		p = p->next;//向下一节点移动
	}
	return NULL;
}

struct node* tShow(struct node* tail)
{
	while (tail != NULL)
	{
		printf("%d ", tail->num);//打印输出数据
		tail = tail->front;//节点向前移动
	}

	return NULL;
}

int main()
{
	struct node* head,*tail;
	printf("请输入需要保存的非负整数（输入负数即为结束）：\n");

	head = Create();//创建链表

	tail = twoCreate(head);//从后往前连接链表，并返回尾节点

	printf("以下为您保存的非负整数:\n");
	Show(head);//显示链表
	printf("\n以下是从尾节点开始显示链表:\n");
	tShow(tail);//反方向显示链表
	return 0;

}



