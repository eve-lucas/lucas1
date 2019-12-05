//写一个动态顺序表 需要使用malloc开辟动态内存空间  动态顺序表需要结构体定义，需要它的指向存储的指针p，需要指向当前的存储容量size;需要这个顺序表最大的容量capacity,开辟空间
//静态顺序表 就是一个数组
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<assert.h>
#define N 100
#define DEFAULT 100
#pragma once
//定义一个动态的顺序表  typedef加； define 不加分号
typedef int SeqListDataType;//typedef是给一个变量换一个名称，SeqListDataType表示int
////一个静态顺序表有三个元素 数组大小，有效数字的个数
//typedef struct SeqList//定义的结构体名称尽量不要与类型的名称相同
//{
//	SeqListDataType array[N];//长度是定死的，数组的[]可以填变量名称，只能是将变量定义为宏
//	size_t size;//有效数组大小
//};
////一个动态顺序表有三个元素 指向动态开辟数组的指针array，有效数字的个数size_t size，动态开辟的容量size_capacity; size_t表示unsigned int
typedef struct SeqList
{
	SeqListDataType * array;
	size_t size;//有效数字的大小
	size_t capacity;
}SeqList,*pS;  

//上边一行代码可以写成 
//
void SeqListInit(pS ps);//pS表示结构体的指针类型  结构体的指针类型定义时需要写 struct SeqList *ps  结构体的对象 struct SeqList 
void SeqListDestory(pS ps);
int CheckSeqList(pS ps);
void SeqListInsert(pS ps, size_t pos, SeqListDataType x);
void SeqListErease(pS ps, size_t pos);
void PushBack(pS ps, SeqListDataType x);
void PushFront(pS ps, SeqListDataType x);
void PopBack(pS ps);
void PopFront(pS ps);
void SeqListPrint(pS ps);