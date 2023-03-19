#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>

using namespace std;

struct node
{
	int num;
	struct node* next;
};

struct node *Create()
{
	int innum;
	scanf_s("%d", &innum);

	struct node* p1, * p2, * head;
	p1 = (struct node*)malloc(sizeof(node));
	p2 = (struct node*)malloc(sizeof(node));

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
	free(p1);
	p2->next = NULL;
	return head;
}

struct node* Show(struct node *head)
{
	struct node *p = head;
	while (p != NULL)
	{
		printf("%d ", p->num);//打印输出数据
		p = p->next;//向下一节点移动
	}


	return NULL;
}


int main()
{
	struct node* head;
	printf("请输入需要保存的非负整数（输入负数即为结束）：\n");

	head= Create();//创建链表

	printf("以下为您保存的非负整数:\n");
	Show(head);//显示链表
	return 0;

}



