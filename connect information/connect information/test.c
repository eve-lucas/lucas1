#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "Contact.h"//�Լ���ͷ�ļ�
//��һ��ö�٣�ʹswitch����
enum OPTION
{
	EXIT,//���ʹ�ö���
	ADD,
	DEL,
	SEA,
	MOD,
	SHOW,
	SORT,
	LOAD,
	SAVE//���һ����Ҫ����
};

void menu()
{
	printf("********0.exit  1.add  2.del********\n");
	printf("********3.search  4.modify  5.show********\n");
	printf("********6.sort  7.load  8.save********\n");
}

void test()
{
	Contact ct;//����ṹ�����
	Initcontact(&ct);//ȡ�ṹ���ַ����
	Addcontact(&ct);//ȡ�ṹ���ַ����
	Addcontact(&ct);//ȡ�ṹ���ַ����
	Addcontact(&ct);//ȡ�ṹ���ַ����
	Delcontact(&ct);//���Һ�����ɾ���������ã����Բ���д����
}
//�ټ�һ��test������չʾ��Ҫ������Щ����
void testContact()
{
	Contact ct;//����ṹ�����
	Initcontact(&ct);//ȡ�ṹ���ַ����
	int option = 0;
	//���Գ�������ѡ���
	do
	{
		menu();
		//������Щ����������ʹ��switch
		scanf("%d", &option);//scanf���һ����Ҫ�ҼӶ���
		switch (option)
		{
		case EXIT://Ϊ�˷������Ŀɶ��ԣ����Ը�switch��ö������
			break;
		case ADD:
			Addcontact(&ct);
			break;
		case DEL:
			Delcontact(&ct);
			break;
		case SEA:
			Searchcontact(&ct);
			break;
		case MOD:
			Modifycontact(&ct);
			break;
		case SHOW:
			Showcontact(&ct);
			break;
		case SORT:
			Sortcontact(&ct);
			break;
		case LOAD:
			Loadcontact(&ct);
			break;
		case SAVE:
			Savecontact(&ct);
			break;
		default:
			printf("����ѡ��ʧ��");
			break;
		}
	} while (option);
}
//��ͨѶ¼���浽Ӳ����
//void testfile()
//{
//	FILE *file = fopen("test.txt", "r");
//	printf("%p", file);
//	char buffer[100] = {0};//һ�㶨��������ý����ʼ��Ϊ0����ֹ��������֮��Ķ���
//	while (fread(buffer, sizeof(char), 100, file))//���ļ�����Ӧ�ü�ס����⺯��
//	{
//		printf("%s", buffer);
//	}
//	fclose(file);
//
//	file = fopen("test.txt", "w");
//	buffer[50] = 'a';
//	buffer[99] = 'b';
//	fwrite(buffer, sizeof(char), 100, file);//д�ļ���txt�ļ���
//	fclose(file);
//}
int main()
{
	int a = 0;
	//���ò��Ժ���
	testContact();
	//test();�����ϱߵ�test�Ϳ��Բ���Ҫ�����
	//testfile();//����һ���ļ�
	scanf("%d",&a);
	return 0;
}