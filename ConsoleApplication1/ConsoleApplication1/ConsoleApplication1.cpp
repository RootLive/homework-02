// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include<stdlib.h>
#include <iostream>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{

	FILE *f;
	int i=0,n=0,a[10000],max=0,sum=0,j=0,k=1;
	char ky,lj[100];
	if(argc>=2)//如果在命令行中输入了文件名则打开文件
	{
		lj[0]=*argv[1];
		while (*(argv[1]++)!='\0')
		{
			lj[k]=*(argv[1]);
			k++;
		}
		f=fopen(lj,"r");//打开文件

		if(!f)//如果文件打开失败则警告
			printf("文件打开失败！该文件不存在！\n");
		else//如果文件打开成功则读入数据
		{
			fscanf(f,"%d%c",&n,&ky);
			for(i=0;i<n;i++)
				fscanf(f,"%d%c",&a[i],&ky);

			//求出最大子数组和
			max=a[0];//将最大值先置为数组第一个数
			for(i=0;i<n;i++)
			{
				sum=0;
				for(j=i;j<n;j++)
				{
					sum=sum+a[j];//利用上一次结果来运算，可减少一层循环
					if(sum>max) max=sum;
				}

			}
			printf("%d\n",max);
		}	
	}
	else
	{
		printf("请输入文件名！\n");	
	}//如果未输入文件名则警告
	system("pause");
	return 0;
}

