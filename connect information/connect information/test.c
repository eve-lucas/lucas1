#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "Contact.h"//自己的头文件
//给一个枚举，使switch方便
enum OPTION
{
	EXIT,//后边使用逗号
	ADD,
	DEL,
	SEA,
	MOD,
	SHOW,
	SORT,
	LOAD,
	SAVE//最后一个不要符号
};

void menu()
{
	printf("********0.exit  1.add  2.del********\n");
	printf("********3.search  4.modify  5.show********\n");
	printf("********6.sort  7.load  8.save********\n");
}

void test()
{
	Contact ct;//定义结构体变量
	Initcontact(&ct);//取结构体地址传参
	Addcontact(&ct);//取结构体地址传参
	Addcontact(&ct);//取结构体地址传参
	Addcontact(&ct);//取结构体地址传参
	Delcontact(&ct);//查找函数在删除函数调用，所以不用写在这
}
//再加一个test函数，展示需要调用哪些函数
void testContact()
{
	Contact ct;//定义结构体变量
	Initcontact(&ct);//取结构体地址传参
	int option = 0;
	//可以持续输入选项函数
	do
	{
		menu();
		//调用哪些函数，可以使用switch
		scanf("%d", &option);//scanf里边一定不要乱加东西
		switch (option)
		{
		case EXIT://为了方便程序的可读性，可以给switch加枚举类型
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
			printf("输入选项失败");
			break;
		}
	} while (option);
}
//将通讯录保存到硬盘中
//void testfile()
//{
//	FILE *file = fopen("test.txt", "r");
//	printf("%p", file);
//	char buffer[100] = {0};//一般定义数组最好将其初始化为0，防止出现烫烫之类的东西
//	while (fread(buffer, sizeof(char), 100, file))//读文件函数应该记住，查库函数
//	{
//		printf("%s", buffer);
//	}
//	fclose(file);
//
//	file = fopen("test.txt", "w");
//	buffer[50] = 'a';
//	buffer[99] = 'b';
//	fwrite(buffer, sizeof(char), 100, file);//写文件到txt文件中
//	fclose(file);
//}
int main()
{
	int a = 0;
	//调用测试函数
	testContact();
	//test();有了上边的test就可以不需要这个了
	//testfile();//测试一个文件
	scanf("%d",&a);
	return 0;
}