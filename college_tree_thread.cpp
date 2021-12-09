#include<iostream>

using namespace std;

class tb
{
	int data;
	tb *left, *right;
	bool rt, lt;
	
	public :
		tb* insert(tb *, tb *);
		tb* create(int );
		tb* lmn(tb *, tb *);
		void inorder(tb *, tb *);
		tb* preorder(tb *);
};

tb* tb::create(int key)
{
	tb *newnode = new tb;
	newnode->data = key;
	newnode->left = newnode;
	newnode->right = newnode;
	newnode->lt = true;
	newnode->rt = true;
	return newnode;
}

tb* tb::insert(tb *root, tb *head)
{
	int key;
	tb *current;
	cout<<"Enter the element to insert : ";
	cin>>key;
	tb *newnode = create(key);
	if(root==NULL)
	{
		head->left = newnode;
		root = newnode;
		root->left = root->right = head;
		head->lt = false;
		return root;
	}
	else
	{
		current = root;
		while(1)
		{
			if(current->data==key)
			{
				cout<<"\nElement Present Already\n";
				return root;
				break;
			}
			if(key<current->data)
			{
				if(current->lt)
				{
					newnode->left = current->left;
					current->left = newnode;
					newnode->right = current;
					current->lt = false;
					break;
				}
				else
				{
					current = current->left;
				}
			}
			else
			{
				if(current->rt)
				{
					newnode->left = current;
					newnode->right = current->right;
					current->right = newnode;
					current->rt = false;
					break;
				}
				current = current->right;
			}
			
		}
	}
}

tb* tb::lmn(tb *node, tb *head)
{
	if(node==NULL)
	{
		return NULL;
	}
	else
	{
		while(node->left!=head)
		{
			node = node->left;
		}
		return node;
	}
}

void tb::inorder(tb *root, tb *head)
{
	tb *current;
	current = lmn(root, head);
	while(current!=head)
	{
		cout<<current->data;
		if(current->rt)
		{
			current = current->right;
		}
		else
		{
			current = lmn(current->right, head);
		}
	}
}

tb* tb::preorder(tb *node)
{
	cout<<node->data;
	if(node->lt!=false)
	{
		preorder(node->left);
	}
	if(node->rt!=false)
	{
		preorder(node->right);
	}
}

int main()
{
	tb *root =NULL;
	tb t;
	tb *head = t.create(999);
	int c;
	do
	{
		cout<<"\n1]Create Tree\n2]Inorder Traversal\n3]Preorder Traversal\n4]Exit\nEnter Your Choice : ";
		cin>>c;
		switch(c)
		{
			case 1 :
				root = t.insert(root, head);
				break;
			case 2 :
				t.inorder(root, head);
				break;
			case 3 :
				t.preorder(root);
				break;
			case 4 :
				exit(0);
			default : cout<<"\nWrong Choice\n";
				
		}
	}while(c!=4);
}
