#include<iostream>

using namespace std;

class cqueue
{
	int front, rear;
	public :
		cqueue()
		{
			front=rear=-1;
		}
		isqfull(int n);
		void enqueue(int[], int e, int n);
		void dequeue(int [], int n);
		void display(int [], int n);
};

int cqueue::isqfull(int n)
{
	if((rear+1)%n==front)
	{
		cout<<"\nCQ is full\n";
		return 1;
	}
}

void cqueue::enqueue(int a[], int e, int n)
{
	if(front==-1)
	{
		front++;
	}
	rear=(rear+1)%n;
	a[rear]=e;
}

void cqueue::dequeue(int a[], int n)
{
	if(front==-1)
	{
		cout<<"CQ is empty\n";
	}
	//cout<<a[front];
	int item;
	item = a[front];
	cout<<"Element delete is : "<<item<<"\n";
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	{
		front=(front+1)%n;
	}
}

void cqueue::display(int a[], int n)
{
	if(front==-1)
	{
		cout<<"CQ is empty\n";
	}
	//cout<<"\nElements in Queue are : \n";
	for(int i=front; i!=rear;i++)
	{
		cout<<a[front]<<"\n";
	}
}

int main()
{
	int n, c, qf;
	cout<<"Enter The Number of Elements : ";
	cin>>n;
	int a[n];
	cqueue o;
	do
	{
		cout<<"1]Insert an Element in the Queue\n2]Delete an Element from the queue\n3]Display the elements of the queue\n4]Exit\nEnter Your Choice :";
		cin>>c;
		switch(c)
		{
			case 1 :  qf = o.isqfull(n);
			 if(qf!=1)
			 {
			 	int e;
				cout<<"Enter the Element To be entered : ";
				cin>>e;
				o.enqueue(a, e, n);
			 }		
				break;
			case 2 : o.dequeue(a, n);
				break;
			case 3 : o.display(a, n);
				break;
			case 4 : exit(0);
				break;
			default : cout<<"Wrong Choice";
		}
		
	}while(c!=4);
}
