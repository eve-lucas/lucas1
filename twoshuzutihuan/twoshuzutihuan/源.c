#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include<windows.h>
int main()
{
	int a = 0;
	char arr1[] = "welcome to bit";//Ҫ���ַ�������Ϊ�ַ����� char
	char arr2[] = "##############";
	int left = 0;
	//arr[] = { 0, 1, 2, 3 };
	//int right = sizeof(arr) / sizeof(arr[0])-1;
	//arr[] = "bit";
	//int right = sizeof(arr) / sizeof(arr[0])-2;
	//��һ�����ַ������� int right = strlen(arr) - 1;
	int right = strlen(arr1) - 1;
	//һ��һ�����м�ģ������Ǹ�ѭ�� 
	while (left <= right)
	{
		arr2[left] = arr1[left];//��ͬλ�õ��滻
		arr2[right] = arr1[right];
		printf("%s\n", arr2);
		Sleep(1000);//windows���� ֹͣһ��
		system("cls");//�����Ļ
		right--;
		left++;
	}
	scanf("%d ", &a);
	return 0;
}
