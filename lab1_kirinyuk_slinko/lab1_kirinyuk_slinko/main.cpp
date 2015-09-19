#include <iostream>

using namespace std;

int main()
{
	const int m = 3;
	double x[] = {10,10,11};
	double mat[m][m];
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < m; j++)
		{
			mat[j][i] = rand() % 10;
		}
	}

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout<<mat[i][j]<<"\t";
		}
		cout<<"|"<<x[i]<<endl;
	}

	cout<<endl<<endl;

	double b[m];

	for(int i = 0; i < m; i++)
	{
		double h = 0;
		for(int j = 0; j < m; j++)
		{
			h += (mat[i][j] * x[i]);
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
		for(int i = k; i < m; i++)
		{
				double a = mat[i][k];
				if(a != 0 && a != 1)
				{
					for(int j = 0; j < m; j++)
					{
						mat[i][j] /= a;
					}

					b[i] /= a;
				}
		}
		
		for(int i = k + 1; i < m; i++)
		{
			if(mat[i][k] != 0)
			{
				for(int j = 0; j < m; j++)
				{
					mat[i][j] -= mat[k][j];
				}
				b[i] -= b[k];
			}
		}
		for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout<<mat[i][j]<<"\t\t";
		}
		cout<<b[i]<<endl;
	}
		cout<<endl;
		
	}
		
	//обратно
	for(int k = m - 1; k > 0; k--)
	{
		for(int i = k; i >= 0; i--)
		{
			double a = mat[i][k];
			if(a != 0 && a != 1)
			{
				for(int j = m-1; j >= 0; j--)
				{
					mat[i][j] /= a;
				}
				b[i] /= a;
			}
		}

		for(int i = k - 1; i >= 0; i--)
		{
			if(mat[i][k] != 0)
			{
				for(int j = m - 1; j >=0; j--)
				{
					mat[i][j] -= mat[k][j];
				}
				b[i] -= b[k];
			}
		}
		for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout<<mat[i][j]<<"\t\t";
		}
		cout<<b[i]<<endl;
	}
		cout<<endl;
	}

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout<<mat[i][j]<<"\t\t";
		}
		cout<<b[i]<<endl;
	}

	for(int i = 0; i < m; i++)
	{
		b[i] /= mat[i][i];
		mat[i][i] /= mat[i][i];
	}

	cout<<endl;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout<<mat[i][j]<<"\t\t";
		}
		cout<<b[i]<<endl;
	}


	system("pause");
}