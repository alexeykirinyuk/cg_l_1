#include <iostream>

using namespace std;

int main()
{
	const int m = 10;
	double x[] = {8,7,6,34,754,76,234,86,23,8765};
	double mat[m][m];
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < m; j++)
		{
			mat[j][i] = rand() % 1748;
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
			h += (mat[i][j] * x[j]);
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
		//���������, ��� �� ������ ��� �������� ���� = 1
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
	}
		
	//�������
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
			cout<<mat[i][j]<<"\t";
		}
		cout<<b[i]<<endl;
	}


	system("pause");
}