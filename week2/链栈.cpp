#include<stdio.h>
#include<math.h>
#include<string.h>
#include<string>
#include<iostream>

using namespace std;

typedef int ElemType;


typedef struct StackNode//构建节点
{
	ElemType data;
	struct StackNode *next;
}StackNode,*LinkStackPrt;


typedef struct LinkStack {//构建链栈
	LinkStackPrt top;
	int count;
}LinkStack;

bool StackEmpty(LinkStack S)
{
	if (S.count == 0)
	{
		return true;//栈空
	}
	else
	{
		return false;//不空
	}
}

void InitStack(LinkStack *S)
{
	S->count = 0;
	S->top = NULL;//将链栈最后一个指向空，避免访问错误
}

int Push(LinkStack* S, ElemType e) {
	LinkStackPrt p = (LinkStackPrt)malloc(sizeof(StackNode));
	p->data = e;
	p->next = S->top;    //把当前的栈顶元素赋值给新节点的直接后继
	S->top = p; //将新的结点S赋值给栈顶指针
	S->count++;
	return 1;
}

int Pop(LinkStack* S) {
	LinkStackPrt p;
	if (StackEmpty(*S)) {
		return 1;
	}
	p = S->top; //将栈顶结点赋值给p
	S->top = S->top->next;  //使得栈顶指针下移一位，指向后一结点
	free(p);    //释放结点p
	S->count--;
	return 0;
}

void printfStack(LinkStack* S)
{
	LinkStackPrt p = S->top;//从栈顶开始

	while (p!=NULL)
	{
		
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");

}

int main()
{
	LinkStack S;//申请栈
	ElemType e;

	InitStack(&S);//初始化栈链元素个数


	printf("请选择你所需要运行的功能(该栈的元素均为整数):\n");//用户提示
	printf("1.入栈一个元素\n");
	printf("2.出栈一个元素\n");
	printf("3.检查栈内元素个数\n");
	printf("4.检查栈内包含的元素\n");
	printf("5.结束程序\n");
	printf("\n");

	while (scanf_s("%d",&e)!=EOF)
	{
		if (e == 1)//入栈操作
		{
			printf("请输入需要入栈的元素:\n");
			int a;
			scanf_s("%d", &a);
			Push(&S,a);
			printf("入栈成功!\n");
		}
		else if (e == 2)
		{
			if (Pop(&S))//判断是否为空
			{
				printf("您的栈为空，无法出栈元素\n");
			}
			else
			{
				printf("出栈成功\n");
			}
		}
		else if (e == 3)//栈链个数
		{
			printf("您的栈链的元素有%d个\n",S.count);
		}
		else if (e == 4)//检查栈链
		{
			printf("您的栈链为:\n");
			printfStack(&S);
		}
		else if (e == 5)//结束程序
		{
			printf("程序结束\n");
			break;
		}
		printf("请选择你所需要运行的功能(该栈的元素均为整数):\n");

	}


	return 0;
}