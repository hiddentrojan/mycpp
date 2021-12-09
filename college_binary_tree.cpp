#include<iostream>

using namespace std;

class binary
{
	public :
		binary *left, *right;
		int data;
		binary *create(int );
		int search(int , binary *);
		binary *insert(binary *);
		void inorder(binary *);
};

binary *binary::create(int key)
{
	binary *newnode = new binary;
	newnode->data = key;
	newnode->left = NULL;
	newnode->right = NULL;
	cout<<"Created";
	return newnode;
	
}

int binary::search(int key, binary *root)
{
	binary *current; 
	current = root;
	//cout<<current->data;
	while(current->data!=key)
	{
		if(current->data>key)
		{
			current = current->left;
			cout<<"present left";
		}
		else
		{
			current = current->right;
			cout<<"present right";
		}
	}
	if(current->data==key)
	{
		cout<<"found";
		return 1;
	}
	else
	{
		cout<<"not found";
		return 0;
	}
}

binary *binary::insert(binary *root)
{
	binary *current, *newnodes, *parent;
	int key, valid;
	cout<<"\nEnter the Element : ";
	cin>>key;
	current = root;
	cout<<"creating newnode";
	newnodes = create(key);
	if(root==NULL)
	{
		root = newnodes;
		return root;
	}
	else
	{
		valid = search(key, current);
		if(valid==1)
		{
			cout<<"\nElement already present\n";
		}
		while(valid!=1)
		{
			if(key<current->data)
			{
				//parent = current;
				current = current->left;
				if(current==NULL)
				{
					current->left = newnodes;
					return current;
					break;
				}	
			}
			else
			{
				//parent = current;
				current = current->right;
				if(current==NULL)
				{
					current->right = newnodes;
					return current;
					break;
				}
			}
		}
	}
	return current;
}

void binary::inorder(binary *root)
{
	binary *current; 
	current = root;
	if(current==NULL)
	{
		return;
	}
	inorder(current->left);
	cout<<"\t"<<current->data;
	inorder(current->right);
}

int main()
{
	binary b1;
	binary *root;
	root = NULL;
	int c;
	do
	{
		cout<<"\n1]Insert\n2]Inorder\n3]Exit\nEnter Your Choice : ";
		cin>>c;
		switch(c)
		{
			case 1 :
				root = b1.insert(root);
				break;
			case 2 :
				b1.inorder(root);
				break;
			case 3 :
				exit(0);
			default : cout<<"\nWrong Choice\n";
		}
	}while(c!=3);
}
