#define _CRT_SECURE_NO_WARNINGS 1

////初始化我们的函数
#include <stdio.h>
//初始化的过程中，我们应该去加我们自己定义的头文件
#include "Contact.h"//自己头文件的引用使用" .h"
#include <string.h>
#include <malloc.h>
void Initcontact(pContact pc)  //初始化就是初始化size的大小
{
	//将通讯录大小初始化为0
	pc->size = 0;//静态开辟空间可以只初始化大小就可以
	
	//动态开辟通讯录的话，初始化时应该开辟空间
	pc->data = (info*)malloc(sizeof(info)* DEFAULT);
	pc->capacity = DEFAULT;
}
int Checkcapacity(pContact pc)//扩容返回的是指针类型
{
	if (pc->size == pc->capacity)
	{   
		/*pc->data = realloc(pc->data, pc->capacity + 10);*///realloc的使用方法 要注意，参数，给谁开，开多少
        //用malloc进行扩容
		info *tmp = (info*)malloc(sizeof(info)*(pc->capacity + 10));
		if (tmp == NULL)
		{
			printf("增容失败");
			return 0;
		}
		memcpy(tmp, pc->data, sizeof(info)*pc->size);//拷贝的是pc->size 的大小到tmp
		free(pc->data);
		pc->data = tmp;
		(pc->capacity )+= 10;
	}
	return 1;
	
	//判断是否增容成功
	/*if (pc->data == NULL)
	{
		printf("增容失败");
		return 0;
	}*/
	/*return 1;*/
}
void Addcontact(pContact pc)//定义一个个人信息变量，将其元素充实完整，然后给通讯录赋值该变量
{
	//加入个人信息，需要定义一个个人信息变量
	info curinfo;
	//通讯录满了,静态模式下
	/*if (pc->size == MAX)
	{
		printf("通讯录满了");
	}*/
	/////动态模式下
	if (Checkcapacity(pc) == 0)
	{
		printf("通讯录满了");
	}
	//通讯录不满
	else
	{
		printf("请输入姓名\n");
		scanf("%s", curinfo.name);//记得加#define _CRT_SECURE_NO_WARNINGS 1
		printf("请输入性别\n");
		scanf("%s", curinfo.gender);
		printf("请输入年龄\n");
		scanf("%d", &curinfo.age);
		printf("请输入电话\n");
		scanf("%s", curinfo.tel);
		printf("请输入地址\n");
		scanf("%s", curinfo.add);
		pc->data[pc ->size] = curinfo;///int arr[]={0};     arr[i] = 值 //这个需要研究一下
		pc->size++;
	}
}

void Delcontact(pContact pc)//通过姓名查找到当前人员，然后给他后一个覆盖前一个
{
	//删除联系人姓名就可以删除完毕
	char name[NAME_MAX];
	printf("输入删除人姓名\n");
	scanf("%s", name);//要删除一个人首先要找到他
	//假设实现了查找接口
	int pos = Findcontact(pc, name);
	if (pos == -1)
	{
		printf("删除失败");
		return;
	}
	//删除类似一个覆盖的操作
	for (int i = pos; i < pc->size-1; i++)//
	{
		pc->data[i] = pc->data[i + 1];////当前只有6个人 pos 0-5;size 1-6 第六个人给第五个人，用pos循环，肯定到5就ok,所以i<size-1=5
	}
	pc->size--;
	printf("删除成功\n");
}
//这是一个通过查找名字返回当前人所在位置的值
int Findcontact(pContact pc, char* name)//查找姓名的过程，用一个循环
{
	for (int i = 0; i < pc->size; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)//查找结构体info名称 ，看名字是否相等，使用strcmp
			return i;
	}
	return -1;
}

void Searchcontact(pContact pc)//通过姓名查找然后修改
{
	char name[NAME_MAX];
	printf("请输入查找人员的姓名：");
	scanf("%s", name);//这块输入查找人员的姓名
	int pos = Findcontact(pc, name);
	if (pos == -1)
	{
		printf("查找失败");
		return;
	}
	printf("姓名：%s\n", pc->data[pos].name);
	printf("性别：%s\n", pc->data[pos].gender);
	printf("年龄：%d\n", pc->data[pos].age);
	printf("电话：%s\n", pc->data[pos].tel);
	printf("地址：%s\n", pc->data[pos].add);
}

void Modifycontact(pContact pc)//把当前姓名给他重新scanf一下，就可以修改
{
	char name[NAME_MAX];
	printf("请输入修改人的姓名");
	scanf("%s", name);
	int pos = Findcontact(pc, name);
	if (pos == -1)
	{
		printf("查找失败");
		return;
	} 
	printf("请输入姓名\n");
	scanf("%s", pc->data[pos].name);
	printf("请输入性别\n");
	scanf("%s", pc->data[pos].gender);
	printf("请输入年龄\n");
	scanf("%d", &pc->data[pos].age);
	printf("请输入电话\n");
	scanf("%s", pc->data[pos].tel);
	printf("请输入地址\n");
	scanf("%s", pc->data[pos].add);
	printf("修改成功");
}

void Sortcontact(pContact pc)//排通讯录，是一个冒泡法//按姓名比较
{
	info  tmp;
	//冒泡排序法，是从 0-size-1, 0-size-2, 0-size-3,一直到0
	for (int j = pc->size; j > 0; --j)//第一次排序 去掉最后一位，第二次排序，一直到剩下最后一个
	{
		for (int i = 0; i < j-1; ++i)//冒泡排序法，是从 0-size-1, 0-size-2, 0-size-3,一直到0
		{
			//这块一定要注意这个（）的写法
			if (strcmp(pc->data[i].name, pc->data[i+1].name) > 0)//用姓名比较字符串大小，可以用strcmp
			{
				tmp = pc->data[i + 1];
				pc->data[i + 1] = pc->data[i];
				pc->data[i] = tmp;
				
			}
		}
	}
}
void Showcontact(pContact pc)//展示人员信息，可以展示一个也可以展示所有
{
	for (int i = 0; i < pc->size; i++)
	{
		printf("***********第%d个人**********", i);
		printf("姓名：%s\n", pc->data[i].name);
		printf("性别：%s\n", pc->data[i].gender);
		printf("年龄：%d\n", pc->data[i].age);
		printf("电话：%s\n", pc->data[i].tel);
		printf("地址：%s\n", pc->data[i].add);
	}
}

void Loadcontact(pContact pc)
{
	FILE *file = fopen("contact.dat", "rb");//写代码要小心
	if (file == NULL)
	{
		printf("文件打开失败");
		return;
	}
	info buffer;//定义一个接收一个个人员信息的内存文件
	while (fread(&buffer, sizeof(info), 1, file))//把文件中的信息读到buffer内村中
	{
		if (Checkcapacity(pc))
		{
			pc->data[pc->size] = buffer;//将读到的文件放入结构体中，调用函数进行打印
			pc->size++;
		}
	}
	fclose(file);
}
void Savecontact(pContact pc)
{
	FILE *file = fopen("contact.dat", "wb");//这里可以创建一个.dat文件
	if (file == NULL)
	{
		printf("文件打开失败");
		return;
	}
	for (int i = 0; i < pc->size; ++i)//从内存向.dat文件写通讯录信息
	{
		fwrite(pc->data+i, sizeof(info), 1, file);//因为写的二进制，所以data只能+i
	}
	fclose(file);
}