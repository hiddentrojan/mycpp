#include<iostream>

using namespace std;

class bst
{
	public :
		int data;
		bst *left, *right;
		bst *create(int );
		int search(bst *, int );
		bst *insert(bst *);
		bst *del(bst *);
		void inorder(bst *);
};

bst *bst::create(int item)
{
	bst *newnode = new bst;
	newnode->data = item;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

int bst::search(bst *root, int key)
{
	bst *current;
	current = root;
	
	while(current->data!=key)
	{
		if(current->data>key)
		{
			if(current->left==NULL)
			{
				return 0;
			}
			else
			{
				current = current->left;
			}
		}
		else
		{
			if(current->right==NULL)
			{
				return 0;
			}
			else
			{
				current = current->right;	
			}
		}
	}
	if(current->data==key)
	{
		return 1;
	}
}

bst *bst::insert(bst *root)
{
	int element;
	cout<<"Enter the Number : ";
	cin>>element;
	bst *cnode, *current;
	cnode = create(element);
	if(root==NULL)
	{
		root = cnode;
		return root;
	}
	else
	{
		current = root;
		int valid;
		valid = search(current, element);
		if(valid==1)
		{
			cout<<"\nElement is already there\n";
			return root;
		}
		else
		{
			while(current!=NULL)
			{
				if(current->data>element)
				{
					if(current->left==NULL)
					{
						current->left=cnode;
						return root;
					}
					else
					{
						current = current->left;
					}
				}
				else
				{
					if(current->right==NULL)
					{
						current->right=cnode;
						return root;
					}
					else
					{
						current = current->right;
					}
				}
			}

		}
	}
}

bst *bst::del(bst *root)
{
	bst *current;
	int d;
	cout<<"\nEnter the element to be deleted : ";
	cin>>d;
	current = root;
	while(1)
	{
		if(current->data>d)
		{
			if(current->data==d)
			{
				break;
			}
			else
			{
				current = current->left;
			}
			
		}
		else
		{
			if(current->data==d)
			{
				break;
			}
			else
			{
				current = current->right;
			}
		}
	}
	if(current->left==NULL && current->right==NULL)
	{
		current = NULL;
		return root;
	}
	if(current->left!=NULL && current->right!=NULL)
	{
		bst *parent, *rv;
		current = current->left;
		parent = current;
		while(current->right!=NULL)
		{
			rv = current;
			current = current->right;
		}
		parent->data = rv->data;
		return root;
	}
	else
	{
		bst *temp;
		if(current->left!=NULL)
		{
			temp = current;
			current =temp->left;
			return root;
		}
		if(current->right!=NULL)
		{
			temp = current;
			current= temp->right;
			return root;
		}
	}
}

void bst::inorder(bst *root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
}

int main()
{
	bst obj;
	bst *root, *head;
	root = NULL;
	int ch;
	do
	{
		cout<<"\n1]Insert\n2]Delete\n3]Inorder\n4]Exit\nEnter Your Choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1 :
				root = obj.insert(root);
				break;
			case 2 :
				root = obj.del(root);
				break;
			case 3 :
				obj.inorder(root);
				break;
			case 4 :
				exit(0);
			default : cout<<"\nWrong Choice\n";
		}
	}while(ch!=4);
}
