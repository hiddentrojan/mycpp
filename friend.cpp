#include<iostream>

using namespace std;

class distance
{
	private :
		int m;
		int cm;
	public :
		friend void add(int m, int cm);
		friend void add2(int m, int cm);
};

void add(int m, int cm)
{
	int add = m+(cm/100);
	cout<<add<<" is in meter\n";
}

void add2(int m, int cm)
{
	int add = cm+(m*100);
	cout<<add<<" is in centimeter\n";
}

int main()
{
	int m, cm, c;
	cout<<"Enter the distance in meter :";
	cin>>m;
	cout<<"Enter the distance in centimeter :";
	cin>>cm;
	do
	{
		cout<<"\n1]Centimeter\n2]Meter\n3]Exit\nEnter Your Choice : ";
		cin>>c;
		switch(c)
		{
			case 1 : add2(m, cm);
			break;
			case 2 : add(m, cm);
			break;
			case 3 : exit(0);
			break;
			default : cout<<"Wrong Choice";
		}
	}while(c!=3);
}
