#include<iostream>

using namespace std;

class tree
{
	tree *left, *right;
	public :
		int data;
		tree* create(int);
		void inorder(tree *);
		int search(int , tree *);
		tree* insert(int , tree *);
};

tree* tree::create(int op)
{
	tree *nodenew = new tree();
	nodenew->data=op;
	nodenew->left=NULL;
	nodenew->right=NULL;
	return nodenew;
}

void tree::inorder(tree *root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
}

int tree::search(int key, tree *root)
{
	tree *current;
	current = root;
	if(current->data==key)
	 return 1;
	while(current->data!=key)
	{
		if(current->data>key)
		 current = current->left;
		else if(current->data<key)
		 current = current->right;
		else
		{
			return 0;
			break;
		}
	}
}

tree* tree::insert(int key, tree *root)
{
	tree *current, *parent;
	current = root;
	tree *newnode = create(key);
	int valid;
	if(root==NULL)
	 root = newnode;
	else
	{
		valid = search(key, root);
		while(valid!=1)
		{
			if(key<current->data)
			{
				parent = current;
				current = current->left;
				if(current==NULL)
				{
					parent->left = newnode;
				}
			}
			else
			{
				parent = current;
				current = current->right;
				if(current==NULL)
				{
					parent->right = newnode;
				}
			}
		}
	}
	return parent;
}

int main()
{
	tree t1;
	tree *root;
	int c, n;
	do
	{
		cout<<"\n1]Create a Tree\n2]Insert\n3]Inorder\n4]Exit\nEnter Your Choice : ";
		cin>>c;
		switch(c)
		{
			case 1 :
				cout<<"\nEnter an element : ";
				cin>>n;
				root = t1.create(n);
				break;
			case 2 :
				cout<<"\nEnter an element : ";
				cin>>n;
				root = t1.insert(n, root);
				break;
			case 3 :
				t1.inorder(root);
				break;
			case 4 : exit(0);
			default : cout<<"\nWrong Choice\n";
		}
	}while(c!=4);
	
}
