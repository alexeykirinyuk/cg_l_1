#include <iostream>

using namespace std;

int main()
{
	const int m = 10;
	double x[] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 10};
	double mat[m][m];
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < m; j++)
		{
			mat[j][i] = rand() % 100;
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
	for(int k = 0; k < m; k++)
	{
		//нормируем, что бы первые все элементы были = 1
		for(int i = 0; i < m; i++)
		{
				double a = mat[i][k];
				if(a != 0 && a != 1)
				{
					for(int j = k; j < m; j++)
					{
						mat[i][j] /= a;
					}
					b[i] /= a;
				}
		}

		for(int i = k + 1; i < m; i++)
		{
			
			for(int j = 0; j < m; j++)
			{
				mat[i][j] -= mat[k][j];
			}
			b[i] -= b[k];
		}
	}

	//обратно
	for(int k = m - 1; k > 0; k--)
	{
		for(int i = m - 1; i >= 0; i--)
		{
			double a = mat[i][k];
			if(a != 0 && a != 1)
			{
				for(int j = k; j >= 0; j--)
				{
					mat[i][j] /= a;
				}
				b[i] /= a;
			}
		}
		for(int i = k - 1; i >= 0; i--)
		{
			for(int j = m - 1; j >=0; j--)
			{
				mat[i][j] -= mat[k][j];
			}
			b[i] -= b[k];
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