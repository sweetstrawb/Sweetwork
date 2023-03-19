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
	scanf_s("%d", &innum);//��������

	struct node* p1, * p2, * head;
	p1 = (struct node*)malloc(sizeof(node));
	p2 = (struct node*)malloc(sizeof(node));

	p1->front = NULL;//����ͷ�ڵ��ǰһ�ڵ�Ϊ��ָ��
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
	free(p1);//����ռ�
	p2->next = NULL;//��֤����鿴���ݲ�����
	return head;
}

struct node *twoCreate(struct node *head)
{
	struct node* p1, * p2;
	p1 = head;
	p2 = head;//�ڶ����ڵ���������Ľڵ�
	p2 = p2->next;

	while (p2 != NULL)
	{
		p2->front = p1;//��һ���ڵ�ָ��ǰһ���ڵ�
		p2 = p2->next;//�ڵ������ƶ�
		p1 = p1->next;//�ڵ������ƶ�
	}

	return p1;
}


struct node* Show(struct node* head)
{
	struct node* p = head;
	while (p != NULL)
	{
		printf("%d ", p->num);//��ӡ�������
		p = p->next;//����һ�ڵ��ƶ�
	}
	return NULL;
}

struct node* tShow(struct node* tail)
{
	while (tail != NULL)
	{
		printf("%d ", tail->num);//��ӡ�������
		tail = tail->front;//�ڵ���ǰ�ƶ�
	}

	return NULL;
}

int main()
{
	struct node* head,*tail;
	printf("��������Ҫ����ķǸ����������븺����Ϊ��������\n");

	head = Create();//��������

	tail = twoCreate(head);//�Ӻ���ǰ��������������β�ڵ�

	printf("����Ϊ������ķǸ�����:\n");
	Show(head);//��ʾ����
	printf("\n�����Ǵ�β�ڵ㿪ʼ��ʾ����:\n");
	tShow(tail);//��������ʾ����
	return 0;

}



