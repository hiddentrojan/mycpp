#include<iostream>

using namespace std;

class cq
{
	int f, r;
	public :
		cq()
		{
			f=r=-1;
		}
		checker(int);
		enqueue(int[], int, int);
		dequeue(int[], int);
		display(int[], int);
};

int cq::checker(int n)
{
	if((r+1)%n==f)
	{
		cout<<"\nCQ is full";
		return 1;
	}
}

int cq::enqueue(int q[], int n, int e)
{
	if(f==-1)
	{
		f++;
	}
	else
	{
		r=(r+1)%n;
		q[r]=e;
	}
}

int cq::dequeue(int q[], int n)
{
	if(f==-1)
	{
		cout<<"\nCQ is empty\n";
	}
	int item;
	item=q[f];
	cout<<"Element deleted is "<<item<<"\n";
	if(f==r)
	{
		f=r=-1;
	}
	else
	{
		f=(f+1)%n;
	}
}

int cq::display(int q[], int n)
{
	if(f==-1)
	{
		cout<<"\nQueue is Empty\n";
	}
	cout<<"Queue :";
	for(int i=f; i<=r; i++)
	{
		cout<<q[f]<<"\n";
	}
}


int main()
{
	int n, c, checker;
	cout<<"Enter the number of elements : ";
	cin>>n;
	int q[n];
	cq qc;
	do
	{
		cout<<"\n1]Insert\n2]Delete\n3]Display\n4]Exit\nEnter Your Choice : ";
		cin>>c;
		switch(c)
		{
			case 1 :
				checker= qc.checker(n);
				if(checker!=1)
				{
					int element;
					cout<<"Element:";
					cin>>element;
					qc.enqueue(q, n, element);
				}
				break;
			case 2 :
				qc.dequeue(q, n);
				break;
			case 3 :
				qc.display(q, n);
				break;
			case 4 :
				break;
			default : cout<<"\nWrong Choice\n";
		}
		
	}while(c!=4);
}
