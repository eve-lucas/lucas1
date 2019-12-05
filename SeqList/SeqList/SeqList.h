//дһ����̬˳��� ��Ҫʹ��malloc���ٶ�̬�ڴ�ռ�  ��̬˳�����Ҫ�ṹ�嶨�壬��Ҫ����ָ��洢��ָ��p����Ҫָ��ǰ�Ĵ洢����size;��Ҫ���˳�����������capacity,���ٿռ�
//��̬˳��� ����һ������
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<assert.h>
#define N 100
#define DEFAULT 100
#pragma once
//����һ����̬��˳���  typedef�ӣ� define ���ӷֺ�
typedef int SeqListDataType;//typedef�Ǹ�һ��������һ�����ƣ�SeqListDataType��ʾint
////һ����̬˳���������Ԫ�� �����С����Ч���ֵĸ���
//typedef struct SeqList//����Ľṹ�����ƾ�����Ҫ�����͵�������ͬ
//{
//	SeqListDataType array[N];//�����Ƕ����ģ������[]������������ƣ�ֻ���ǽ���������Ϊ��
//	size_t size;//��Ч�����С
//};
////һ����̬˳���������Ԫ�� ָ��̬���������ָ��array����Ч���ֵĸ���size_t size����̬���ٵ�����size_capacity; size_t��ʾunsigned int
typedef struct SeqList
{
	SeqListDataType * array;
	size_t size;//��Ч���ֵĴ�С
	size_t capacity;
}SeqList,*pS;  

//�ϱ�һ�д������д�� 
//
void SeqListInit(pS ps);//pS��ʾ�ṹ���ָ������  �ṹ���ָ�����Ͷ���ʱ��Ҫд struct SeqList *ps  �ṹ��Ķ��� struct SeqList 
void SeqListDestory(pS ps);
int CheckSeqList(pS ps);
void SeqListInsert(pS ps, size_t pos, SeqListDataType x);
void SeqListErease(pS ps, size_t pos);
void PushBack(pS ps, SeqListDataType x);
void PushFront(pS ps, SeqListDataType x);
void PopBack(pS ps);
void PopFront(pS ps);
void SeqListPrint(pS ps);