//左值：a = 20 a是左值-空间   int b = a;a是右值-指内容
//表示出来 数组替换不能用数组名来表示，因为左值要为空间，但是数组名只是一个地址
//实现1/1-1/2+1/3-1/4  -1/99+1/100；
//先加起来，在改变其他 分子1 分母1-100 循环 1/i  1、加减可以判断i为奇数或者偶数  判奇偶用取余%2
//2、一加一减也可以用flag  flag = -flag;
//将1/i加起来  打印double 用%lf
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	//分母要循环 所以定义变量i,要得总数，所以定义变量sum
	int i = 0;//控制第一种方法
	int j = 0;//控制第二种方法
	double sum1 = 0;//分母判奇偶第一种方法求和  加起来的数字可能为double
	double sum2 = 0;//定义标签求和
	int flag = 1;
	//要将数据加起来，必须for循环 sum+=数字
	for (i = 1; i < 101; i++)
	{   //题干为一加一减 方法一 i为偶是负 i为奇是正 判奇偶取余
		if (i % 2 == 0)
		{
			sum1 -= 1.0 / i;//加负值就是减
		}
		else
		{
			sum1 += 1.0 / i;//由于后边加的都是小数，所以除号上下要有一个数为float
		}
	}
	for (j = 1; j < 101; j++)
	{
		sum2 += flag*(1.0 / j);
		flag = -flag; //1与-1来回倒
	}
	printf("%lf\n", sum1);//打印小数点后边好多位的double数字要用lf   0.688172
	printf("%lf\n", sum2);//
	scanf("%d", &sum1);
	return 0;
}