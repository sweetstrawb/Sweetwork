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
	printf("�������ַ���(ÿ�����ַ����Իس��ֿ�������������ֱ�ӻس�)��\n");
	gets_s(b);//����һ���ַ��� 
	struct node* p, * p2, * head;
	p = (struct node*)malloc(sizeof(node));//�����ڴ� 
	p2 = (struct node*)malloc(sizeof(node));//�����ڴ� 
	head = p;
	while (b[0] != '\0')
	{
		strcpy_s(p->a, b);//�洢�ַ��� 
		p2->next = p;//�洢��һ���ڵ� 
		p2 = p;//���Ƶ�ַ 
		p = p->next;//����һ�ڵ�ת�� 
		gets_s(b);//����һ���ַ��� 
		p = (struct node*)malloc(sizeof(node));//���·����ڴ� 
	}
	free(p);//�ͷſռ䣬����ռ�й¶ 
	p2->next = NULL;
	return head;
}

struct node* FindMid(struct node *head)
{
	struct node* p1, * p2;
	p1 = head;//p1�ٶ�Ϊ1
	p2 = head;//p2�ٶ�Ϊ2

	while (p2 != NULL)
	{
		
		p2 = p2->next;//����һ��

		if (p2 == NULL)
		{
			printf("��������һ���е�,Ϊ:\n");
			printf("%s\n", p1->a);
			break;//����ѭ��
		}		
		p2 = p2->next;//����һ��

		if (p2 == NULL)
		{
			printf("�������������е㣬�ֱ�Ϊ:\n");
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