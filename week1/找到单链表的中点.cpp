#include<stdio.h>
#include<string>
#include<math.h>
#include<iostream>
#include<cstring>
#include<string.h>


using namespace std;

struct node
{
	char a[100];
	struct node* next;
};

struct node* Create()
{
	char b[100];
	printf("请输入字符串(每两个字符串以回车分开，结束创建请直接回车)：\n");
	gets_s(b);//输入一个字符串 
	struct node* p, * p2, * head;
	p = (struct node*)malloc(sizeof(node));//分配内存 
	p2 = (struct node*)malloc(sizeof(node));//分配内存 
	head = p;
	while (b[0] != '\0')
	{
		strcpy_s(p->a, b);//存储字符串 
		p2->next = p;//存储下一个节点 
		p2 = p;//复制地址 
		p = p->next;//向下一节点转移 
		gets_s(b);//输入一个字符串 
		p = (struct node*)malloc(sizeof(node));//重新分配内存 
	}
	free(p);//释放空间，避免空间泄露 
	p2->next = NULL;
	return head;
}

struct node* FindMid(struct node *head)
{
	struct node* p1, * p2;
	p1 = head;//p1速度为1
	p2 = head;//p2速度为2

	while (p2 != NULL)
	{
		
		p2 = p2->next;//先走一步

		if (p2 == NULL)
		{
			printf("该链表有一个中点,为:\n");
			printf("%s\n", p1->a);
			break;//跳出循环
		}		
		p2 = p2->next;//再走一步

		if (p2 == NULL)
		{
			printf("该链表有两个中点，分别为:\n");
			printf("%s\n", p1->a);
			p1 = p1->next;
			printf("%s\n", p1->a);
			break;
		}	
		p1 = p1->next;
	}
	return NULL;
}


int main()
{
	struct node* head;
	head = Create();

	FindMid(head);
	return 0;
}