#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include<windows.h>
int main()
{
	int a = 0;
	char arr1[] = "welcome to bit";//要将字符串定义为字符数组 char
	char arr2[] = "##############";
	int left = 0;
	//arr[] = { 0, 1, 2, 3 };
	//int right = sizeof(arr) / sizeof(arr[0])-1;
	//arr[] = "bit";
	//int right = sizeof(arr) / sizeof(arr[0])-2;
	//但一般求字符串长度 int right = strlen(arr) - 1;
	int right = strlen(arr1) - 1;
	//一个一个往中间改，所以是个循环 
	while (left <= right)
	{
		arr2[left] = arr1[left];//相同位置的替换
		arr2[right] = arr1[right];
		printf("%s\n", arr2);
		Sleep(1000);//windows函数 停止一秒
		system("cls");//清空屏幕
		right--;
		left++;
	}
	scanf("%d ", &a);
	return 0;
}
