#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int k, const int n,
	const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < n - 1)
		Create(a, k, n, Low, High, i, j + 1);
	else
		if (i < k - 1)
			Create(a, k, n, Low, High, i + 1, 0);
}
void Input(int** a, const int k, const int n, int i, int j)
{
	cout << "a[" << i << "][" << j << "] = ";
	cin >> a[i][j];
	if (j < n - 1)
		Input(a,k, n, i, j + 1);
	else
		if (i < k - 1)
		{
			cout << endl;
			Input(a, k, n, i + 1, 0);
		}
		else
			cout << endl;
}

void Print(int** a, const int k, const int n, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < n - 1)
		Print(a, k, n, i, j + 1);
	else
		if (i < k - 1)
		{
			cout << endl;
			Print(a, k, n, i + 1, 0);
		}
		else
			cout << endl << endl;
}
int Character(int** a, const int k, const int i,const int j, int S)
{
	if (a[i][j] < 0 && !(a[i][j] % 2 == 0))
		S += abs(a[i][j]);
	if (i < k - 1)
		return Character(a, k, i + 1, j, S);
	else
		return S;
}
void Change(int** a, const int col1, const int col2, const int k, int i)
{
	int tmp = a[i][col1];
	a[i][col1] = a[i][col2];
	a[i][col2] = tmp;
	if (i < k - 1)
		return  Change(a, col1, col2, k, i + 1);
}
void Sort(int** a, const int k, const int n, int i0, int i1)
{
	if (Character(a, k, 0, i0, 0) > Character(a, k, 0, i1, 0))
		Change(a, i1, i1 + 1, k, 0);
	if (i1 < n -i0 - 2)
		Sort(a, k, n, i0, i1 + 1);
	else
		if (i0 < n - 2)
			Sort(a, k, n, i0 + 1, 0);
}
int main()
{
	srand((unsigned)time(NULL));
	int Low = -10;
	int High = 15;
	int k, n;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;

	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];

	//Create(a, k, n, Low, High,0,0);
	Input(a, k, n, 0, 0);
	Print(a, k, n,0,0);

	Sort(a, k, n,0,0);
	Print(a, k, n,0,0);


	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;
	return 0;

}