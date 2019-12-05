#include "SeqList.h"

//直接开空间一部分空间
//void SeqListInit1(pS ps)//这个名称必须要有
//{   
//	ps->array = (SeqList*)malloc(sizeof(SeqList)*DEFAULT);//(SeqList*)一定要加*
//	ps->size = 0;
//	ps->capacity = DEFAULT;//在检查空间的时候开空间
//}

void SeqListInit(pS ps)//这个名称必须要有
{
	ps->array = NULL;
	ps->size = 0;
	ps->capacity = 0;//在检查空间的时候开空间
}

void SeqListDestory(pS ps)
{   assert(ps);
	free(ps->array);//freemalloc的空间
	ps->array = NULL;//指针为空
	ps->size = 0; //所有的大小都为0
	ps->capacity = 0;
}

int CheckSeqList(pS ps)
{
	if (ps->capacity == ps->size)
	{
		int newcapacity = ps->capacity = 0 ? 4 : ps->capacity * 2;
		//用realloc增容
		ps->array = (SeqListDataType *)realloc(ps->array, newcapacity);
		ps->capacity = newcapacity;
		//用malloc增容
		/*SeqListDataType * newarray = (SeqListDataType *)malloc(sizeof(SeqListDataType)*newcapacity);
		if(newarray=NULL)
		{
			printf("增容失败");
			return 0;
		}
		//将原来数组的东西拷到新malloc的数组中
		memcpy(newarray, ps->array, sizeof(SeqListDataType)*ps->size);//(目标指针，源指针，赋值的字节数)
		//free掉原来数组，新数组指针给原数组，新容量给原容量
		free(ps->array);
		ps->array = newarray;
		ps ->capacity = newcapacity;*/
	}
	return 1;
}
	
void SeqListPrint(pS ps)
{
	//要打印就得先查看空间
	//如果有assert(ps),则不需要判断CheckList()==1 
		size_t i = 0;
		for (i = 0; i < ps->size; i++)
		{
			printf("%d", ps->array[i]);
		}	
}
//头插尾插 头删尾删都是调用了inseart插入函数和ereasr删除函数
void PushBack(pS ps, SeqListDataType x)
{
	assert(ps);
	SeqListInsert(ps, ps->size, x);
}
void PushFront(pS ps, SeqListDataType x)
{
	assert(ps);
	SeqListInsert(ps, 0, x);
}
void PopBack(pS ps)
{
	assert(ps);
	SeqListErease(ps, ps->size);
}
void PopFront(pS ps)
{
	assert(ps);
	SeqListErease(ps, 0);
}
//一个插入数组的函数
void SeqListInsert(pS ps, size_t pos, SeqListDataType x)
{
	assert(ps);
	assert(pos <= ps->size);
	if (CheckSeqList(ps) == 1)
	{
		size_t end = ps->size;
		while (pos < end)
		{
			ps->array[end] = ps->array[end - 1];
			end--;
		}
		ps->array[pos] = x;
		ps->size++;
	}
}
//一个删除数组的函数
void SeqListErease(pS ps, size_t pos)
{
	assert(ps);
	assert(pos <= ps ->size);
	size_t start = pos+1;
	while (start < ps->size)
	{
		ps->array[start - 1] = ps->array[start];
		start++; 
	}
	ps->size--;
}


