//求1-100 数字中出现9的个数  分别判断数字的每一位是否为9
//i%10 ==9 表示最后一位 为9
//i/10 ==9 十位为9 
//注意坑 还有一个99的情况出现，符合两种条件
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{   //1-100数字都判断，所以加循环
	int i = 1;
	int j = 1;
	//最终求有多少个数字 需要计数器变量
	int count1 = 0;
	int count2 = 0;
	for (i = 1; i < 101; i++)
	{
		if (i % 10 == 9)//表示个位为9
		{
			count1++;
		}
		if (i / 10 == 9)  //不用elseif 的原因 是99符合两种情况 判断十位为9
		{
			count1++;
		}
	}
	for (j = 1; j < 1000; j++)
	{
		if (j > 100)
		{
			if (i % 100 == 9)
			{
				count2++;
			}
			if ((j / 10) % 10 == 9)//表示个位为9
			{
				count2++;
			}
			if ((j / 10) / 10 == 9)  //不用elseif 的原因 是99符合两种情况 判断十位为9
			{
				count2++;
			}
		}
		if ((j) % 10 == 9)//表示个位为9
		{
			count2++;
		}
		if ((j) / 10 == 9)  //不用elseif 的原因 是99符合两种情况 判断十位为9
		{
			count2++;
		}

	}
	printf("%d\n", count1);
	printf("%d\n", count2);
	scanf("%d", &count1);
	return 0;
}
