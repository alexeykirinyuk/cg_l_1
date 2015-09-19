#include <iostream>

using namespace std;

int main()
{
	const int m = 10;
	double x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	double mat[m][m];
	
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < m; j++)
		{
			mat[j][i] = rand() % 101;
			cout<<mat[j][i] << "\t";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
	double b[10];
	for(int i = 0; i < m; i++)
	{
		double h = 0;
		for(int j = 0; j< m; j++)
		{
			h += mat[j][i] * x[j];
		}
		b[i] = h;
	}

	for(int i = 0; i < m; i++)
	{
		cout<<b[i]<<"\t";
	}
	cout<<endl;

	for(int hh = 0; hh < m; hh++)
	{
		//нормируем, что бы первые все элементы были = 1
		for(int i = 0; i < m; i++)
		{
			double a = mat[i][hh];
			for(int j = 0; j < m; j++)
			{
				mat[i][j] = mat[i][j] / a;
			}
			b[i] /= a;
		}
		for(int i = 1; i < m; i++)
		{
			for(int j = 0; j < m; j++)
			{
				mat[i][j] -= mat[hh][j];
			}
			b[i] -= b[hh];
		}
	}


	cout<<endl<<endl<<endl;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout<<mat[i][j]<<"\t";
		}
		cout<<b[i]<<endl;
	}


	system("pause");
}