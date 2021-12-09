#include<iostream>

using namespace std;

class binary
{
	int data;
	binary *link, *top;
	public :
		binary()
		{
			top=NULL;
		}
		void push(int );
		void display();
		void ntb(int );
		
};

void binary::push(int ele)
{
	binary *newnode = new binary();
	newnode->data = ele;
	newnode->link=NULL;
	if(top==NULL)
	{
		top=newnode;
	}
	else
	{
		newnode->link=top;
		top=newnode;
	}
}

void binary::display()
{
	binary *current;
	current = top;
	while(current!=NULL)
	{
		cout<<current->data;
		current = current->link;
	}
}

void binary::ntb(int num)
{
	binary *current;
	int i, bi;
	for(i=0;num>0;i++)
	{
		bi = num%2;
		push(bi);
		num=num/2;
	}
	cout<<"Binary Conversion of the Number is  : ";
	display();
}

int main()
{
	binary b;
	int num, c;
	cout<<"Enter the Number to be converted into binary : ";
	cin>>num;
	b.ntb(num);		
}
