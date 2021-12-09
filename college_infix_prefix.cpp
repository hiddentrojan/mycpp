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
		void reverse(char[], int);
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
	cout<<"\nPostfix : "<<postfix<<"\n";
	reverse(postfix, 1);
}


void sll::reverse(char infix[], int flag)
{
	int i=0, count=0, j=0;
	char prefix[10], inprefix[10];
	//cout<<infix;
	//cout<<"\n"<<i<<j<<count<<flag<<"\n";
	while(infix[i]!='\0')
	{
		count+=1;
		i++;
		//cout<<"\n"<<count<<"\n";
	}
	count-=1;
	//cout<<count<<"\n";
	//cout<<prefix<<i<<j<<count;
	/*for(i=0;i<count+1;i++)
	{
		cout<<prefix[i]<<"\n";
	}
	*/
	if(flag==0)
	{
		for(i=count;i>=0;i--)
		{
			if(infix[i]=='(')
			{
				prefix[j]=')';
				j++;
				//cout<<"\n 0 \n";
			}
			else if(infix[i]==')')
			{
				prefix[j]='(';
				j++;
				//cout<<"\n 0 \n";
			}
			else
			{
				prefix[j]=infix[i];
				j++;
				//cout<<"\n 0 \n";
			}
		}
		prefix[j]='\0'; // definig value of end of the string
		postfix(prefix);
	}
	else
	{
		for(i=count;i>=0;i--)
		{
			inprefix[j]=infix[i];
			//cout<<inprefix[j];
			j++;
			//cout<<inprefix;
		}
		inprefix[j]='\0';
		cout<<"\nPrefix : "<<inprefix<<"\n";
	}
}

int main()
{
	sll p;
	char a[10];
	cout<<"Enter the infix : ";
	cin>>a;
	p.reverse(a, 0);
}
