///////头文件包含自定义变量 结构体 函数（实现函数声明与函数定义分离）
//定义一个联系人结构体 struct info;
//通讯录里边人的信息有 1、姓名char[] 2、性别char[]3、电话号码char[],不能用int[]，因为整形范围不足 4、地址char[] 5、年龄int
//需要定义变量长度  1、NAME_MAX 2、GENDER_MAX  3、TELE_MAX 4、ADDR_MAX  5、int 年龄可以直接赋值
//定义一个info个人信息类型就好
//定义一个联系人通讯录，相当于一个记录本
//可以存储的通讯录人个数 1、整体人的个数，info data[]; 现存储的个数 int size;
//需要定义变量长度 1、MAX;
//定义一个通讯录的类型，在加一个指针类型，在进行通讯录查询存储时，需要传通讯录结构体的指针

//通化录功能
//1、初始化通讯话Init 2、增加联系人Add 3、删除联系人Del4、寻找联系人 Search5、更新联系人Modify
#pragma once;
#define NAME_MAX 100 //定义的宏都不加分号
#define GENDER_MAX 20
#define TELE_MAX 20
#define ADDR_MAX 100
#define MAX 200//通讯录大小   关于通讯录的大小我们可以用多少 开多少，所以可以用malloc来开
#define DEFAULT 1
typedef struct info  //结构体类型定义，使用typedef
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tel[TELE_MAX];
	char add[ADDR_MAX];
}info;
//静态存储
//typedef struct Contact
//{
//	info data[MAX];//是通讯录人类型在通讯录中  通讯录人数组
//	int size;//当前个人信息人数
//}Contact, *pContact;//定义结构体指针是在进行通讯录变化时，需要传递指针
////动态存储
typedef struct Contact
{
	info *data;//定义一个通讯录指针，可以给他开辟空间
	int size;
	int capacity;//记录当前容量
}Contact,*pContact;



//做通讯录功能 一个接口
void Initcontact(pContact pc);// 函数声明 类型+变量名 结构体指针类型+变量 int add(int x);int add(int* x)
int Checkcapacity(pContact pc);//检查动态开辟的空间，当前的容量
void Addcontact(pContact pc);
void Delcontact(pContact pc);
//删除一个人员，就得寻找他姓名
int Findcontact(pContact pc, char* name);//寻找该人的所在通讯录的位置
void Searchcontact(pContact pc);//寻找一个人，也是使用他的姓名寻找
void Modifycontact(pContact pc);
void Sortcontact(pContact pc);
void Showcontact(pContact pc);
//可以将通讯录进行一个永久的存储
void Loadcontact(pContact pc);
void Savecontact(pContact pc);