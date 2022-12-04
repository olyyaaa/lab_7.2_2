// lab_7.2_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** y, const int k, const int n, const int Low, const int High, int i, int j)
{
	y[i][j] = Low + rand() % (High - Low + 1);

	if (j < n - 1)
		Create(y, k, n, Low, High, i, j + 1);
	else
		if (i < k - 1)
			Create(y, k, n, Low, High, i + 1, 0);
}

void Print(int** y, const int k, const int n, int i, int j)
{
	cout << setw(4) << y[i][j];
	if (j < n - 1)
		Print(y, k, n, i, j + 1);
	else
		if (i < k - 1)
		{
			cout << endl;
			Print(y, k, n, i + 1, 0);
		}
		else
			cout << endl << endl;

}

int iMax(int** y, int k, int n, int i, int j, int max, int imax)
{
	if (y[i][j] > max) {
		max = y[i][j];
		imax = j;
	}
	if (j < n - 1)
		iMax(y, k, n, i, j + 1, max, imax);
	else
		return imax;
}


int iMin(int** y, int k, int n, int i, int j, int min, int imin)
{
	if (y[i][j] < min) {
		min = y[i][j];
		imin = j;
	}
	if (j < n - 1)
		iMin(y, k, n, i, j + 1, min, imin);
	else
		return imin;
}

void Change(int** y, int k, int n, int i, int max, int imax, int min, int imin)
{
	int IndexOfMax = iMax(y, k, n, i, 0, max, imax);
	int IndexOfMin = iMin(y, k, n, i - 1, 0, min, imin);

	int tmp = y[i][IndexOfMax];
	y[i][IndexOfMax] = y[i - 1][IndexOfMin];
	y[i - 1][IndexOfMin] = tmp;

	if (i < k - 1)
		Change(y, k, n, i + 2, max, imax, min, imin);
}
int Sum(int** a, const int rowCount, const int colCount, int i, int j, int S)
{
	if (colCount < rowCount - 1)
		S += a[i][j];
	if (j < colCount - 1)
		return Sum(a, rowCount, colCount, i, j + 1, S);
	else
		if (i < rowCount - 1)
			return Sum(a, rowCount, colCount, i + 1, 0, S);
		else
			return S;
}

int main()
{
	srand((unsigned)time(NULL));
	int Low = 8;
	int High = 73;
	int k;
	int n;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;
	int i = 0;
	int j = 0;
	int** y = new int* [k];
	for (int i = 0; i < k; i++)
		y[i] = new int[n];
	int max = -10;
	int imax = 0;
	int min = 100;
	int imin = 0;
	Create(y, k, n, Low, High, i, j);
	cout << "Create" << endl;
	Print(y, k, n, i, j);
	cout << "Print" << endl;
	iMax(y, k, n, i, j, max, imax);
	cout << "iMax" << endl;
	iMin(y, k, n, i, j, min, imin);
	cout << "iMin" << endl;
	Change(y, k, n, 1, max, imax, min, imin);
	cout << "Change" << endl;
	Print(y, k, n, i, j);
	int S = 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
