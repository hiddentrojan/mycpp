#include<iostream>

using namespace std;

class sll
{
	char data;
	sll *link, *top;
	public:
		sll()
		{
			top=NULL;
		}
		void insert(char);
		void pop();
		void display();
};

void sll::insert(char item)
{
	sll *newnode = new sll();
	newnode->data=item;
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

void sll::pop()
{
	sll *nodenew = new sll();
	nodenew=top;
	top=top->link;
	cout<<"\nPopped Element :"<<nodenew->data<<"\n";
}

void sll::display()
{
	sll *ptr;
	ptr=top;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"\t";
		ptr=ptr->link;
	}
}

int main()
{
	sll p;
	char a[10];
	cout<<"Enter the element : ";
	for(int i=0;i<5;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<5;i++)
	{
		p.insert(a[i]);
	}
	p.pop();
	p.display();
}
