#include<iostream>
#include<stdio.h>

using namespace std;

class sll
{
	int data;
	sll *link, *top;
	public:
		sll()
		{
			top=NULL;
		}
		void push(int);
		void pop();
		void postfix(char[]);
		void post_eval(char[]);
};

void sll::push(int item)
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
	if(top==NULL)
	{
		cout<<"It is Empty";
	}
	else
	{
		top=top->link;
	}
}

int priority(char x)
{
	if(x=='^')
	 return 3;
	else if((x=='*') || (x=='/'))
	 return 2;
	else if((x=='+') || (x=='-'))
	 return 1;
	else
	 return 0;
}

void sll::postfix(char infix[])
{
	int i=0, j=0, instack, incoming;
	char postfix[10];
	while(infix[i]!='\0')
	{
		if(!isalnum(infix[i]))
		{
			if(infix[i]=='(')
			{
				push(infix[i]);
				i++;
			}
			else
			{
				if(top==NULL)
				{
					push(infix[i]);
					i++;
				}
				else
				{
					if(infix[i]==')')
					{
						while(top->data!='(')
						{
							postfix[j]=top->data;
							j++;
							pop();
						}
						pop();
						i++;
					}
					else
					{
						instack=priority(top->data);
						incoming=priority(infix[i]);
						if(instack>=incoming)
						{
							postfix[j]=top->data;
							j++;
							pop();
							push(infix[i]);
							i++;
						}
						else
						{
							push(infix[i]);
							i++;
						}
					}
					
				}
			}
		}
		else
		{
			postfix[j]=infix[i];
			i++;j++;
		}
	}
	while(top!=NULL)
	{
		postfix[j]=top->data;
		pop();
		j++;
	}
	postfix[j]='\0';
	cout<<postfix;
	post_eval(postfix);
}

int calculate(int y, int x, char op)
{
	if(op=='/' && y!=0)
	 return(x/y);
	else if(op=='+')
	 return(x+y);
	else if(op=='*')
	 return(x*y);
	else if(op=='^')
	 return(x^y);
	else
	 return(x-y);
}

void sll::post_eval(char postfix[])
{
	int n, x, y, cal, ans, i=0;
	do
	{
		while(isalnum(postfix[i]))
		{
			if(!isalpha(postfix[i]))
			{
				push(postfix[i]);
			}
			else
			{
				cout<<"\nEnter a numerical value for "<<postfix[i]<<":";
				cin>>n;
				push(n);
			}
			i++;
		}
		y=top->data;
		pop();
		x=top->data;
		pop();
		cal=calculate(y, x, postfix[i]);
		i++;
		push(cal);
	}while(postfix[i]!='\0');
	
	ans=top->data;
	cout<<"\nPostfix Evaluated :"<<ans;
	pop();
}

int main()
{
	sll p;
	char a[10];
	cout<<"Enter the infix : ";
	cin>>a;
	p.postfix(a);
}
