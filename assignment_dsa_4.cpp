#include<iostream>

using namespace std;

void ntb(int num)
{
	int binary[10], i;
	for(i=0;num>0;i++)
	{
		binary[i]=num%2;
		num=num/2;
	}
	cout<<"Binary Conversion of the Number is  : ";
	for(i=i-1;i>=0;i--)
	{
		cout<<binary[i];
	}
}

int main()
{
	int num, c;
	do
	{
		cout<<"Enter the Number to be converted into binary : ";
		cin>>num;
		ntb(num);
		cout<<"\n1]Try Again\n2]Exit\nEnter Your Choice :";
		cin>>c;
		switch(c)
		{
			case 1 :
				break;
			case 2 :
				exit(0);
			default : cout<<"\nWrong Choice\n";
		}
	}while(c!=2);
		
}
