#include<iostream>

using namespace std;

template<class t>
class matrix
{
	int mat[5][5];
	int row, col;
	public  :
		void getdata();
		void add(matrix , matrix);
		void display();
};

template<class t>
void matrix::getdata()
{
	cout<<"Row  :";
	cin>>row;
	cout<<"Column :";
	cin>>col;
	for(int i = 0;i<row;i++)
	{
		for(int j = 0;j<col;j++)
		{
			cout<<"\nElements :";
			cin>>mat[i][j];
		}
	}
}

template<class t>
void matrix::add(matrix m1, matrix m2)
{
	if(m1.row==m2.row && m1.col==m2.col)
	{
		row = m1.row;
		col = m1.col;
		for(int i = 0;i<row;i++)
		{
			for(int j = 0;j<col;j++)
			{
				mat[i][j] = m1.mat[i][j]+m2.mat[i][j];
			}
		}
	}
	else
	{
		cout<<"\nAddition is not possible\n";
	}
}

template<class t>
void matrix::display()
{
	for(int i = 0;i<row;i++)
	{
		cout<<"\n";
		for(int j = 0;j<col;j++)
		{
			cout<<mat[i][j]<<"\t";
		}
	}
}

int main()
{
	matrix<int> m1, m2, m3;
	cout<<"\nFirst\n";
	m1.getdata();
	cout<<"\nSecond\n";
	m2.getdata();
	m3.add(m1, m2);
	cout<<"\nAddition of Matrix";
	m3.display();
}
