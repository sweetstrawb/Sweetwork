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

		p1->num = innum;//���������������
		p2->next = p1;
		p2 = p1;

		p1 = p1->next;//�ڵ��ƶ�
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
		printf("%d ", p->num);//��ӡ�������
		p = p->next;//����һ�ڵ��ƶ�
	}


	return NULL;
}


int main()
{
	struct node* head;
	printf("��������Ҫ����ķǸ����������븺����Ϊ��������\n");

	head= Create();//��������

	printf("����Ϊ������ķǸ�����:\n");
	Show(head);//��ʾ����
	return 0;

}



