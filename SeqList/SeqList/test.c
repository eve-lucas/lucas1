#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "SeqList.h"
int main()
{
	SeqList sq;//定义结构体变量
	int a = 0;
	SeqListInit(&sq);
	SeqListDestory(&sq);
	SeqListPrint(&sq);
	PushBack(&sq,1);
	PushBack(&sq,2);
	PushBack(&sq,3);
	PushFront(&sq, 3);
	PushFront(&sq, 2);
	PopBack(&sq);
	PopFront(&sq);
	SeqListPrint(&sq);
	scanf("%d", a);
	return 0;
}
