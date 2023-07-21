/*

Inorder Sequence : Left, Root, Right

*/

#include<iostream>

using namespace std;

class tree
{
	tree *left, *right;
	public :
		char data;
		tree* create(char);
		void expression(char[]);
		void inorder(tree *);
		void ninorder(tree *);
};

class stack
{
	
	public :
		tree *t;
		stack *top, *link;
		stack()
		{
			top=NULL;
		}
		void push(tree *);
		void pop();
};

void stack::push(tree *item)
{
	stack *newnode = new stack();
	newnode->t=item;
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

void stack::pop()
{
	if(top==NULL)
	{
		cout<<"\nStack is empty\n";
	}
	else
	{
		stack *ptr = top;
		top = top->link;
		delete ptr;
	}
}

tree* tree::create(char op)
{
	tree *nodenew = new tree();
	nodenew->data=op;
	nodenew->left=NULL;
	nodenew->right=NULL;
	return nodenew;
}

void tree::inorder(tree *ptr2)
{
	if(ptr2==NULL)
	{
		return;
	}
	inorder(ptr2->left);
	cout<<ptr2->data;
	inorder(ptr2->right);
}

void tree::ninorder(tree *ptr3)
{
	stack s;
	tree *curr=ptr3;
	while(1)
	{
		while(curr)
		{
			s.push(curr);
			curr=curr->left;
		}
		if(s.top!=NULL)
		{
			curr=s.top->t;
			s.pop();
			cout<<curr->data;
			curr=curr->right;
		}
		else
		 break;
	}
}

void tree::expression(char postfix[])
{
	int i=0;
	tree *ptr1, *ans;
	stack s;
	while(postfix[i]!='\0')
	{
		ptr1 = create(postfix[i]);
		if(isalnum(postfix[i]))
		{
			s.push(ptr1);	
		}
		else
		{
			ptr1->right=s.top->t;
			s.pop();
			ptr1->left=s.top->t;
			s.pop();
			s.push(ptr1);
		}
		i++;
	}
	ans = s.top->t;
	cout<<"Inorder Recursive : ";
	inorder(ptr1);
	cout<<"\nInorder Non Recursive : ";
	ninorder(ptr1);
}

int main()
{
	tree t1;
	stack s1;
	char postfix[10];
	cout<<"Enter the Postfix Expression :";
	cin>>postfix;
	t1.expression(postfix);
}
