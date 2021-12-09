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
		void postfix(char[], int, int);
		void reverse(char[], int, int);
		void postfix_evaluation(char[]);
		void prefix_evaluation(char[], int);
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

void sll::postfix(char infix[], int flag, int flag_1)
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
	if(flag==1)
	{
		if(flag_1==12)
		{
			reverse(postfix, 1, 10);
		}
		else
		{
			reverse(postfix, 1, 1);
		}
	}
	else if(flag==10)
	{
		postfix_evaluation(postfix);
	}
	else
	{
		cout<<"PostFix : "<<postfix<<"\n";
	}
	
}


void sll::reverse(char infix[], int flag, int flag1)
{
	int i=0, count=0, j=0;
	char prefix[10], inprefix[10];
	while(infix[i]!='\0')
	{
		count+=1;
		i++;
	}
	count-=1;
	if(flag==0)
	{
		for(i=count;i>=0;i--)
		{
			if(infix[i]=='(')
			{
				prefix[j]=')';
				j++;
			}
			else if(infix[i]==')')
			{
				prefix[j]='(';
				j++;
			}
			else
			{
				prefix[j]=infix[i];
				j++;
			}
		}
		prefix[j]='\0'; // declaring value of end of the string
		postfix(prefix, 1, flag1);
	}
	else
	{
		for(i=count;i>=0;i--)
		{
			inprefix[j]=infix[i];
			j++;
		}
		inprefix[j]='\0';
		if(flag1==10)
		{
			prefix_evaluation(inprefix, count);
		}
		else
		{
			cout<<"\nPrefix : "<<inprefix<<"\n";
		}
	}
}

int calculate(int x, int y, char op)
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

void sll::prefix_evaluation(char infix[], int count)
{
	int i=count, n, x, y, cal, result;
	while(infix[i]!='\0')
	{
		while(isalnum(infix[i]))
		{
			if(isalpha(infix[i]))
			{
				cout<<"\nEnter the value of "<<infix[i]<<" : ";
				cin>>n;
				push(n);
				i--;
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
		i--;
		push(cal);
	}
	result=top->data;
	cout<<"Prefix Evaluation : "<<result;
	pop();
}

int main()
{
	sll p;
	char a[10], result_get[10], result_get2[10];
	cout<<"Enter the Infix Expression : ";
	cin>>a;
	int c;
	do
	{
		cout<<"\n1] Postfix\n2] Prefix\n3]Postfix Evaluation\n4]Prefix Evaluation\n5]Exit\nEnter Your Choice : ";
		cin>>c;
		switch(c)
		{
			case 1 : 
				p.postfix(a, 0, 101);
				break;
			case 2 :
				p.reverse(a, 0, 1);
				break;
			case 3 :
				p.postfix(a, 10, 101);
				break;
			case 4 :
				p.reverse(a, 0, 12);
				break;
			case 5 : exit(0);
				break;
			default : cout<<"\nWrong Choice\n";
				
		}
	}while(c!=5);
}
