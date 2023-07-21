#include<iostream>

using namespace std;

//class declaraion

class cqueue
{
	int front, rear;
	public :
		cqueue() // default constructor for setting value of front and rear to -1 according to condition of circular queue
		{
			front=rear=-1;
		}
		// declaring methods of the class
		int isqfull(int);
		void enqueue(int[], int, int);
		void dequeue(int [], int);
		void display(int [], int);
};

int cqueue::isqfull(int n)
{
	/*
	Elements are added from rear, this condition checks if rear is equal to front.
	When rear is equal to front then queue is full, according to circular queue condition.
	*/
	if((rear+1)%n==front)
	{
		cout<<"\nCQ is full\n";
		return 1; // returns to qf integer, declared in main class
	}
}

void cqueue::enqueue(int cq[], int n, int e)
{
	if(front==-1)
	{
		front++;
	}
	rear=(rear+1)%n; // increasing value of rear
	cq[rear]=e; // adding element in the queue
}

void cqueue::dequeue(int cq[], int n)
{
	if(front==-1)
	{
		cout<<"CQ is empty\n";
	}
	//cout<<a[front];
	int item;
	item = cq[front]; // element get stored in item
	cout<<"\nElement delete is : "<<item<<"\n"; // displays deleted element
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	{
		front=(front+1)%n; // increasing value of front
	}
}

void cqueue::display(int cq[], int n)
{
	int i;
	if(front==-1)
	{
		cout<<"CQ is empty\n";
	}
	//cout<<"\nElements in Queue are : \n";
	for(i=front; i!=rear;i=(i+1)%n) 
	{
		cout<<cq[i]<<"\n";
	}
	cout<<cq[i];
}

int main()
{
	/*
	n : stores the number of elements
	c : stores the choice for switch case
	qf : stores the return value of isqfull function
	*/
	int n, c, qf;
	cout<<"Enter The Number of Elements : ";
	cin>>n;
	int cq[n]; // array creation
	cqueue obj; // object creation of a class
	do
	{
		cout<<"\n1]Insert an Element\n2]Delete an Element\n3]Display the Queue\n4]Exit\nEnter Your Choice :"; // menu
		cin>>c;
		switch(c)
		{
			case 1 : 
				// inserting element
				 qf = obj.isqfull(n); // condition to check if queue is full
				 if(qf!=1) // if return value stored in qf is 1 then it means the queue is full and it will not enter the element
				 {
			 		int element;
					cout<<"Enter the Element To be entered : ";
					cin>>element;
					obj.enqueue(cq, n, element);
				 }		
				break;
			case 2 :
				// deleting element
				obj.dequeue(cq, n);
				break;
			case 3 :
				// displaying queue
				obj.display(cq, n);
				break;
			case 4 :
				//exiting the switch case
				exit(0);
				break;
			default :
				// responds when user chooses invalid case 
				cout<<"\nWrong Choice\n";
		}
		
	}while(c!=4); // exits do...while loop when c becomes 4
}
