// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include<stdlib.h>
#include <iostream>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{

	FILE *f;
	int i = 0, m = 0, n = 0, j = 0, k = 0, ans = 0, temp = 0, a[50][50], b[50][50][50],p=1;
	int left = 0, right = 0, up = 0, down = 0,left1=0;
	char cs1, cs2;
	char ky,lj[100];
	if(argc>=2)//如果在命令行中输入了文件名则打开文件
	{
		lj[0]=*argv[argc-1];
		while (*(argv[argc-1]++)!='\0')
		{
			lj[p]=*(argv[argc-1]);
			p++;	
		}
		f=fopen(lj,"r");//打开文件

		if(!f)//如果文件打开失败则警告
			printf("文件打开失败！该文件不存在！\n");
		else//如果文件打开成功则读入数据
		{
			fscanf(f,"%d%c",&m,&ky);
			fscanf(f,"%d%c",&n,&ky);
			
			
			if (argc == 2)//无参数情况
			{
				for (i = 0; i<m; i++)
				for (j = 0; j<n; j++)
					fscanf(f, "%d%c", &a[i][j], &ky);//读入数据
				ans = a[0][0];
				for (k = 0; k < n; k++)
				{
					for (i = 0; i < m; i++)
					{
						temp = 0;
						for (j = i; j < m; j++)
						{
							temp = temp + a[j][k];
							b[i][j][k] = temp;
						}
					}
				}
				for (i = 0; i < m; i++)
				for (j = i; j < m; j++)
				{
					temp = 0;
					left1 = 0;
					for (k = 0; k < n; k++)
					{
						temp = temp + b[i][j][k];
						if (temp > ans)
						{
							ans = temp;
							up = i; down = j; left = left1; right = k;
						}
						else if (temp <= 0) { temp = 0; left1=k+1; }
						
					}
				}
				
			}
			else if (argc == 3)
			{
				cs1=*(++argv[1]);
				if (cs1 == 'v')//上下相连情况
				{
					for (i = 0; i < m; i++)
					for (j = 0; j < n; j++)
					{
						fscanf(f, "%d%c", &a[i][j], &ky);//读入数据
						a[i + m][j] = a[i][j];//在原矩阵下面补一个相同的矩阵
					}
					ans = a[0][0];
					for (k = 0; k < n; k++)
					{
						for (i = 0; i < m*2; i++)
						{
							temp = 0;
							for (j = i; j < m*2; j++)
							{
								temp = temp + a[j][k];
								b[i][j][k] = temp;
							}
						}
					}
					for (i = 0; i < m*2; i++)
					for (j = i; j < m*2; j++)
					{
						temp = 0;
						left1 = 0;//每次循环前左界限要置为0
						for (k = 0; k < n; k++)
						{
							temp = temp + b[i][j][k];
							if (temp > ans && j-i<m)
							{
								ans = temp;
								up = i; down = j; left = left1; right = k;
								
								
							}
							else if (temp <= 0&&j - i<m) 
							{ 
								temp = 0; 
								left1 = k + 1; 
								
							}
							
						}
					}
					
						
				}
				else if (cs1 == 'h')//左右相连情况
				{
					for (i = 0; i < m; i++)
					for (j = 0; j < n; j++)
					{
						fscanf(f, "%d%c", &a[i][j], &ky);//读入数据
						a[i][j+n] = a[i][j];//在原矩阵右面补一个相同的矩阵
					}
					ans = a[0][0];
					for (k = 0; k < n*2; k++)
					{
						for (i = 0; i < m; i++)
						{
							temp = 0;
							for (j = i; j < m ; j++)
							{
								temp = temp + a[j][k];
								b[i][j][k] = temp;
							}
						}
					}
					for (i = 0; i < m ; i++)
					for (j = i; j < m ; j++)
					{
						temp = 0;
						left1 = 0;//每次循环前左界限要置为0
						for (k = 0; k < n*2; k++)
						{
							temp = temp + b[i][j][k];
							if (temp > ans && k-left1<n)
							{
								ans = temp;
								up = i; down = j; left = left1; right = k;


							}
							else if (temp <= 0 && k - left1<m)
							{
								temp = 0;
								left1 = k + 1;

							}

						}
					}

				}
			}
			
			printf("当前矩阵的最大子数组和为%d\n", ans);
				
		}	
	}
	
	else//如果未输入文件名则警告
	{
		printf("请输入文件名！\n");	
	}
	system("pause");
	return 0;
}

