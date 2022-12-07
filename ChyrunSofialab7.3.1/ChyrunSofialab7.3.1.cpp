// ChyrunSofialab7.3.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Lab_07_3.cpp
// < Чирун Софія >
// Лабораторна робота № 7.3.1
// Опрацювання динамічних багатовимірних масивів ітераційним способом
// Варіант 18

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
int Part1_Count(int** a, const int rowCount, const int colCount);
void Part2_Count(int** a, const int rowCount, const int colCount);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -12;
	int High = 23;
	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	cout << " k_zero = " << Part1_Count(a, rowCount, colCount) << endl;
	cout << endl;
	Part2_Count(a, rowCount, colCount);
	cout << endl;
	cout << endl;
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	    delete[] a;
	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		    cout << endl;
	}
	cout << endl;
}

int Part1_Count(int** a, const int rowCount, const int colCount)
{
	int k_zero = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (a[i][j] == 0)
			{
			   k_zero++;
			   break;
			}
	return k_zero;
}

void Part2_Count(int** a, const int rowCount, const int colCount)
{
	int b, amaxcount = 0, ncol = 0, maxncol = 0, k_max = 0, count, maxxa = 0, kkmaxx = 0, kmax = 0;
	for (int j = 0; j < colCount; j++)
	{
		for (int i = 0; i < rowCount; i++)
		{
			b = a[i][j];
			count = 0;
			k_max = 0;
			for (int l = i + 1; l < rowCount; l++)
				if (b == a[l][j]) count++;
			if (k_max < count)
			{
			   k_max = count;
			   amaxcount = b;
			   ncol = j;
			}
		}
		if (maxncol < ncol)
		{
		   maxncol = ncol;
		   maxxa = amaxcount;
		   kmax = 0;
		   for (int l = 0; l < rowCount; l++)
			   if (maxxa == a[l][maxncol]) kmax++;
		   kkmaxx = kmax;
		}
	}
	cout << " k_max [" << maxncol + 1 << "] = " << maxxa << " - " << kkmaxx << " times";
}


