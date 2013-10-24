// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include<stdlib.h>
#include <iostream>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{

	FILE *f;
	int i=0,n=0,a[33][33],max=0,sum=0,j=0,k=1,m=0;
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
			fscanf(f,"%d%c",&m,&ky);
			for(i=0;i<n;i++)
				for(j=0;j<m;j++)
				fscanf(f,"%d%c",&a[i][j],&ky);
				
		}	
	}
	
	else//如果未输入文件名则警告
	{
		printf("请输入文件名！\n");	
	}
	system("pause");
	return 0;
}

