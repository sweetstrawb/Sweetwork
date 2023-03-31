#include<stdio.h>
#include<math.h>
#include<string.h>
#include<string>
#include<iostream>

using namespace std;

typedef int ElemType;


typedef struct StackNode//�����ڵ�
{
	ElemType data;
	struct StackNode *next;
}StackNode,*LinkStackPrt;


typedef struct LinkStack {//������ջ
	LinkStackPrt top;
	int count;
}LinkStack;

bool StackEmpty(LinkStack S)
{
	if (S.count == 0)
	{
		return true;//ջ��
	}
	else
	{
		return false;//����
	}
}

void InitStack(LinkStack *S)
{
	S->count = 0;
	S->top = NULL;//����ջ���һ��ָ��գ�������ʴ���
}

int Push(LinkStack* S, ElemType e) {
	LinkStackPrt p = (LinkStackPrt)malloc(sizeof(StackNode));
	p->data = e;
	p->next = S->top;    //�ѵ�ǰ��ջ��Ԫ�ظ�ֵ���½ڵ��ֱ�Ӻ��
	S->top = p; //���µĽ��S��ֵ��ջ��ָ��
	S->count++;
	return 1;
}

int Pop(LinkStack* S) {
	LinkStackPrt p;
	if (StackEmpty(*S)) {
		return 1;
	}
	p = S->top; //��ջ����㸳ֵ��p
	S->top = S->top->next;  //ʹ��ջ��ָ������һλ��ָ���һ���
	free(p);    //�ͷŽ��p
	S->count--;
	return 0;
}

void printfStack(LinkStack* S)
{
	LinkStackPrt p = S->top;//��ջ����ʼ

	while (p!=NULL)
	{
		
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");

}

int main()
{
	LinkStack S;//����ջ
	ElemType e;

	InitStack(&S);//��ʼ��ջ��Ԫ�ظ���


	printf("��ѡ��������Ҫ���еĹ���(��ջ��Ԫ�ؾ�Ϊ����):\n");//�û���ʾ
	printf("1.��ջһ��Ԫ��\n");
	printf("2.��ջһ��Ԫ��\n");
	printf("3.���ջ��Ԫ�ظ���\n");
	printf("4.���ջ�ڰ�����Ԫ��\n");
	printf("5.��������\n");
	printf("\n");

	while (scanf_s("%d",&e)!=EOF)
	{
		if (e == 1)//��ջ����
		{
			printf("��������Ҫ��ջ��Ԫ��:\n");
			int a;
			scanf_s("%d", &a);
			Push(&S,a);
			printf("��ջ�ɹ�!\n");
		}
		else if (e == 2)
		{
			if (Pop(&S))//�ж��Ƿ�Ϊ��
			{
				printf("����ջΪ�գ��޷���ջԪ��\n");
			}
			else
			{
				printf("��ջ�ɹ�\n");
			}
		}
		else if (e == 3)//ջ������
		{
			printf("����ջ����Ԫ����%d��\n",S.count);
		}
		else if (e == 4)//���ջ��
		{
			printf("����ջ��Ϊ:\n");
			printfStack(&S);
		}
		else if (e == 5)//��������
		{
			printf("�������\n");
			break;
		}
		printf("��ѡ��������Ҫ���еĹ���(��ջ��Ԫ�ؾ�Ϊ����):\n");

	}


	return 0;
}