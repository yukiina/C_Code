#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//1. 
//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。

void FindRank()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if ((b == 2 && a != 3) || (b != 2 && a == 3))
						{
							if ((b == 2 && e != 4) || (b != 2 && e == 4))
							{
								if ((c == 1 && d != 2) || (c != 1 && d == 2))
								{
									if ((c == 5 && d != 3) || (c != 5 && d == 3))
									{
										if ((e == 4 && a != 1) || (e != 4 && a == 1))
										{
											if (a*b*c*d*e == 120)
											{
												printf("a=%d,b=%d,c=%d,d=%d,e=%d\n", a, b, c, d, e);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


//2. 
//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个
//嫌疑犯的一个。以下为4个嫌疑犯的供词。
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。

void FindKiller()
{
	int i = 0, a = 0, b = 0, c = 0, d = 0;
	int nd = 0;
	for (i = 1; i <= 4; i++)
	{
		if (i == 1)
		{
			a = 1; c = 1; nd = 1; d = 0;
		}
		if (i == 2)
		{
			a = 0; c = 0; nd = 1; d = 0;
		}
		if (i == 3)
		{
			a = 0; c = 1; nd = 0; d = 0;
		}
		if (i == 4)
		{
			a = 0; c = 1; nd = 1; d = 0;
		}
		if ((a + b + c + d + nd == 1) && (nd == d))printf("A=%d B=%d C=%d D=%d", a, b, c, d);
	}

}


//3.在屏幕上打印杨辉三角。
//  1
// 1  1
//1 2 1
//1 3 3 1

#define N 10
void PrintYangHuiTriangle() // N : 杨辉三角的层数
{
	int arr[N][N] = { 0 };
	for (int i = 0; i < N; i++) //控制层
	{
		for (int m = 0; m < 2 * (N - i) ; m++)
		{
			printf(" ");
		}
		for (int j = 0; j <= i; j++)
		{
			if ((j == 0) || (j == i))
			{
				arr[i][j] = 1;
			}
			else
			{
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
			}
			printf("%4d ", arr[i][j]);
		}
		printf("\n");
	}
}
