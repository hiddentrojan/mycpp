#include<iostream>
#include<stdio.h>

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
		void push(char);
		void pop();
		void postfix(char[]);
		void postfix_evaluation(char[]);
};

void sll::push(char item)
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
	postfix_evaluation(postfix);
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

void sll::postfix_evaluation(char infix[])
{
	int i=0, n, x, y, cal, result;
	while(infix[i]!='\0')
	{
		while(isalnum(infix[i]))
		{
			if(isalpha(infix[i]))
			{
				cout<<"\nEnter the value of "<<infix[i]<<" : ";
				cin>>n;
				push(n);
				i++;
			}
			else
			{
				push(infix[i]);
			}
		}
		y=top->data;
		pop();
		x=top->data;
		pop();
		cal=calculate(y, x, infix[i]);
		i++;
		push(cal);
	}
	result=top->data;
	cout<<"Postfix Evaluation : "<<result;
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
