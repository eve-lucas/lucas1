#define _CRT_SECURE_NO_WARNINGS 1

////��ʼ�����ǵĺ���
#include <stdio.h>
//��ʼ���Ĺ����У�����Ӧ��ȥ�������Լ������ͷ�ļ�
#include "Contact.h"//�Լ�ͷ�ļ�������ʹ��" .h"
#include <string.h>
#include <malloc.h>
void Initcontact(pContact pc)  //��ʼ�����ǳ�ʼ��size�Ĵ�С
{
	//��ͨѶ¼��С��ʼ��Ϊ0
	pc->size = 0;//��̬���ٿռ����ֻ��ʼ����С�Ϳ���
	
	//��̬����ͨѶ¼�Ļ�����ʼ��ʱӦ�ÿ��ٿռ�
	pc->data = (info*)malloc(sizeof(info)* DEFAULT);
	pc->capacity = DEFAULT;
}
int Checkcapacity(pContact pc)//���ݷ��ص���ָ������
{
	if (pc->size == pc->capacity)
	{   
		/*pc->data = realloc(pc->data, pc->capacity + 10);*///realloc��ʹ�÷��� Ҫע�⣬��������˭����������
        //��malloc��������
		info *tmp = (info*)malloc(sizeof(info)*(pc->capacity + 10));
		if (tmp == NULL)
		{
			printf("����ʧ��");
			return 0;
		}
		memcpy(tmp, pc->data, sizeof(info)*pc->size);//��������pc->size �Ĵ�С��tmp
		free(pc->data);
		pc->data = tmp;
		(pc->capacity )+= 10;
	}
	return 1;
	
	//�ж��Ƿ����ݳɹ�
	/*if (pc->data == NULL)
	{
		printf("����ʧ��");
		return 0;
	}*/
	/*return 1;*/
}
void Addcontact(pContact pc)//����һ��������Ϣ����������Ԫ�س�ʵ������Ȼ���ͨѶ¼��ֵ�ñ���
{
	//���������Ϣ����Ҫ����һ��������Ϣ����
	info curinfo;
	//ͨѶ¼����,��̬ģʽ��
	/*if (pc->size == MAX)
	{
		printf("ͨѶ¼����");
	}*/
	/////��̬ģʽ��
	if (Checkcapacity(pc) == 0)
	{
		printf("ͨѶ¼����");
	}
	//ͨѶ¼����
	else
	{
		printf("����������\n");
		scanf("%s", curinfo.name);//�ǵü�#define _CRT_SECURE_NO_WARNINGS 1
		printf("�������Ա�\n");
		scanf("%s", curinfo.gender);
		printf("����������\n");
		scanf("%d", &curinfo.age);
		printf("������绰\n");
		scanf("%s", curinfo.tel);
		printf("�������ַ\n");
		scanf("%s", curinfo.add);
		pc->data[pc ->size] = curinfo;///int arr[]={0};     arr[i] = ֵ //�����Ҫ�о�һ��
		pc->size++;
	}
}

void Delcontact(pContact pc)//ͨ���������ҵ���ǰ��Ա��Ȼ�������һ������ǰһ��
{
	//ɾ����ϵ�������Ϳ���ɾ�����
	char name[NAME_MAX];
	printf("����ɾ��������\n");
	scanf("%s", name);//Ҫɾ��һ��������Ҫ�ҵ���
	//����ʵ���˲��ҽӿ�
	int pos = Findcontact(pc, name);
	if (pos == -1)
	{
		printf("ɾ��ʧ��");
		return;
	}
	//ɾ������һ�����ǵĲ���
	for (int i = pos; i < pc->size-1; i++)//
	{
		pc->data[i] = pc->data[i + 1];////��ǰֻ��6���� pos 0-5;size 1-6 �������˸�������ˣ���posѭ�����϶���5��ok,����i<size-1=5
	}
	pc->size--;
	printf("ɾ���ɹ�\n");
}
//����һ��ͨ���������ַ��ص�ǰ������λ�õ�ֵ
int Findcontact(pContact pc, char* name)//���������Ĺ��̣���һ��ѭ��
{
	for (int i = 0; i < pc->size; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)//���ҽṹ��info���� ���������Ƿ���ȣ�ʹ��strcmp
			return i;
	}
	return -1;
}

void Searchcontact(pContact pc)//ͨ����������Ȼ���޸�
{
	char name[NAME_MAX];
	printf("�����������Ա��������");
	scanf("%s", name);//������������Ա������
	int pos = Findcontact(pc, name);
	if (pos == -1)
	{
		printf("����ʧ��");
		return;
	}
	printf("������%s\n", pc->data[pos].name);
	printf("�Ա�%s\n", pc->data[pos].gender);
	printf("���䣺%d\n", pc->data[pos].age);
	printf("�绰��%s\n", pc->data[pos].tel);
	printf("��ַ��%s\n", pc->data[pos].add);
}

void Modifycontact(pContact pc)//�ѵ�ǰ������������scanfһ�£��Ϳ����޸�
{
	char name[NAME_MAX];
	printf("�������޸��˵�����");
	scanf("%s", name);
	int pos = Findcontact(pc, name);
	if (pos == -1)
	{
		printf("����ʧ��");
		return;
	} 
	printf("����������\n");
	scanf("%s", pc->data[pos].name);
	printf("�������Ա�\n");
	scanf("%s", pc->data[pos].gender);
	printf("����������\n");
	scanf("%d", &pc->data[pos].age);
	printf("������绰\n");
	scanf("%s", pc->data[pos].tel);
	printf("�������ַ\n");
	scanf("%s", pc->data[pos].add);
	printf("�޸ĳɹ�");
}

void Sortcontact(pContact pc)//��ͨѶ¼����һ��ð�ݷ�//�������Ƚ�
{
	info  tmp;
	//ð�����򷨣��Ǵ� 0-size-1, 0-size-2, 0-size-3,һֱ��0
	for (int j = pc->size; j > 0; --j)//��һ������ ȥ�����һλ���ڶ�������һֱ��ʣ�����һ��
	{
		for (int i = 0; i < j-1; ++i)//ð�����򷨣��Ǵ� 0-size-1, 0-size-2, 0-size-3,һֱ��0
		{
			//���һ��Ҫע�����������д��
			if (strcmp(pc->data[i].name, pc->data[i+1].name) > 0)//�������Ƚ��ַ�����С��������strcmp
			{
				tmp = pc->data[i + 1];
				pc->data[i + 1] = pc->data[i];
				pc->data[i] = tmp;
				
			}
		}
	}
}
void Showcontact(pContact pc)//չʾ��Ա��Ϣ������չʾһ��Ҳ����չʾ����
{
	for (int i = 0; i < pc->size; i++)
	{
		printf("***********��%d����**********", i);
		printf("������%s\n", pc->data[i].name);
		printf("�Ա�%s\n", pc->data[i].gender);
		printf("���䣺%d\n", pc->data[i].age);
		printf("�绰��%s\n", pc->data[i].tel);
		printf("��ַ��%s\n", pc->data[i].add);
	}
}

void Loadcontact(pContact pc)
{
	FILE *file = fopen("contact.dat", "rb");//д����ҪС��
	if (file == NULL)
	{
		printf("�ļ���ʧ��");
		return;
	}
	info buffer;//����һ������һ������Ա��Ϣ���ڴ��ļ�
	while (fread(&buffer, sizeof(info), 1, file))//���ļ��е���Ϣ����buffer�ڴ���
	{
		if (Checkcapacity(pc))
		{
			pc->data[pc->size] = buffer;//���������ļ�����ṹ���У����ú������д�ӡ
			pc->size++;
		}
	}
	fclose(file);
}
void Savecontact(pContact pc)
{
	FILE *file = fopen("contact.dat", "wb");//������Դ���һ��.dat�ļ�
	if (file == NULL)
	{
		printf("�ļ���ʧ��");
		return;
	}
	for (int i = 0; i < pc->size; ++i)//���ڴ���.dat�ļ�дͨѶ¼��Ϣ
	{
		fwrite(pc->data+i, sizeof(info), 1, file);//��Ϊд�Ķ����ƣ�����dataֻ��+i
	}
	fclose(file);
}