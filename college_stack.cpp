#include<iostream>

using namespace std;

class stack
{
	int top;
	public:
		stack()
		{
			top=-1;
		}
		int push(int [], int);
		int pop(int[]);
};

int stack::	push(int st[], int item)
{
	st[++top]=item;
}

int stack::pop(int st[])
{
	int element;
	element=st[top--];
	cout<<"Popped Element is : "<<element<<"\n";
}

int main()
{
	int n;
	stack s;
	cout<<"Enter the size of the stack";
	cin>>n;
	int st[n];
	s.push(st, 10);
	s.push(st, 20);
	s.push(st, 30);
	s.pop(st);
	s.pop(st);
}
