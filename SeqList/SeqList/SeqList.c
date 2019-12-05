#include "SeqList.h"

//ֱ�ӿ��ռ�һ���ֿռ�
//void SeqListInit1(pS ps)//������Ʊ���Ҫ��
//{   
//	ps->array = (SeqList*)malloc(sizeof(SeqList)*DEFAULT);//(SeqList*)һ��Ҫ��*
//	ps->size = 0;
//	ps->capacity = DEFAULT;//�ڼ��ռ��ʱ�򿪿ռ�
//}

void SeqListInit(pS ps)//������Ʊ���Ҫ��
{
	ps->array = NULL;
	ps->size = 0;
	ps->capacity = 0;//�ڼ��ռ��ʱ�򿪿ռ�
}

void SeqListDestory(pS ps)
{   assert(ps);
	free(ps->array);//freemalloc�Ŀռ�
	ps->array = NULL;//ָ��Ϊ��
	ps->size = 0; //���еĴ�С��Ϊ0
	ps->capacity = 0;
}

int CheckSeqList(pS ps)
{
	if (ps->capacity == ps->size)
	{
		int newcapacity = ps->capacity = 0 ? 4 : ps->capacity * 2;
		//��realloc����
		ps->array = (SeqListDataType *)realloc(ps->array, newcapacity);
		ps->capacity = newcapacity;
		//��malloc����
		/*SeqListDataType * newarray = (SeqListDataType *)malloc(sizeof(SeqListDataType)*newcapacity);
		if(newarray=NULL)
		{
			printf("����ʧ��");
			return 0;
		}
		//��ԭ������Ķ���������malloc��������
		memcpy(newarray, ps->array, sizeof(SeqListDataType)*ps->size);//(Ŀ��ָ�룬Դָ�룬��ֵ���ֽ���)
		//free��ԭ�����飬������ָ���ԭ���飬��������ԭ����
		free(ps->array);
		ps->array = newarray;
		ps ->capacity = newcapacity;*/
	}
	return 1;
}
	
void SeqListPrint(pS ps)
{
	//Ҫ��ӡ�͵��Ȳ鿴�ռ�
	//�����assert(ps),����Ҫ�ж�CheckList()==1 
		size_t i = 0;
		for (i = 0; i < ps->size; i++)
		{
			printf("%d", ps->array[i]);
		}	
}
//ͷ��β�� ͷɾβɾ���ǵ�����inseart���뺯����ereasrɾ������
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
//һ����������ĺ���
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
//һ��ɾ������ĺ���
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


