#include<iostream> //header file

using namespace std;

class thread
{
	public :
		thread *left, *right;
		bool left_t, right_t;
		int data;
		thread *create(int );
		thread *insert(thread *, thread *);
		thread *leftmostnode(thread *, thread *);
		void inorder(thread *, thread *);
		void preorder(thread *, thread *);
};

thread *thread::create(int key)
{
	thread *newnode =  new thread;
	newnode->data = key;
	newnode->left = newnode;
	newnode->right = newnode;
	newnode->left_t = true;
	newnode->right_t = true;
	return newnode;
}

thread *thread::insert(thread *root, thread *head)
{
	thread *newnode, *current;
	int key;
	cout<<"\nEnter the element : ";
	cin>>key;
	newnode = create(key);
	if(root==NULL)
	{
		head->left = newnode;
		root = newnode;
		root->left=root->right=head;
		head->left_t = false;
		return root;
	}
	else
	{
		current = root;
		while(1)
		{
			if(current->data==key)
			{
				cout<<"\nElement Already there\n";
				//return current;
				break;
			}
			if(key<current->data)
			{
				
				if(current->left_t)
				{
					newnode->left = current->left;
					current->left = newnode;
					newnode->right = current;
					current->left_t = false;
					break;
				}
				else
				{
					current = current->left;
				}
			}
			else
			{
				
				if(current->right_t)
				{
					newnode->left = current;
					newnode->right=current->right;
					current->right = newnode;
					current->right_t = false;
					break;
				}
				else
				{
					current = current->right;
				}
			}
		}
	}
	return current;
}

thread *thread::leftmostnode(thread *node, thread *head)
{
	if(node==NULL)
	{
		return NULL;
	}
	else
	{
		while(node->left!=head)
		{
			if(node->left_t)
			{
				break;
			}
			else
			{
				node = node->left;	
			}
		}
		return node;
	}
}

void thread::inorder(thread *root, thread *head)
{
	thread *current;
	current = leftmostnode(root, head);
	while(current!=head)
	{
		cout<<"\t"<<current->data;
		if(current->right_t)
		{
			current = current->right;
		}
		else
		{
			current = leftmostnode(root, head);
		}
	}
}

void thread::preorder(thread *root, thread *head)
{
	thread *current;
	current = root;
	cout<<"\t"<<current->data;
	while(current!=head)
	{
		cout<<"\t"<<current->data;
		if(current->left_t)
		{
			current = current->left;
		}
		if(current->right_t)
		{
			current = current->right;
		}
	}
}


int main()
{
	thread tb;
	thread *root, *head;
	root = NULL;
	head = tb.create(999);
	int c;
	do
	{
		cout<<"\n1]Create a tree\n2]Inorder Traversal\n3]Preorder Traversal\n4]Exit\nEnter Your Choice : ";
		cin>>c;
		switch(c)
		{
			case 1 :
				root = tb.insert(root, head);
				break;
			case 2 :
				tb.inorder(root, head);
				break;
			case 3 :
				tb.preorder(root, head);
				break;
			case 4 :
				exit(0);
			default : cout<<"\nWrong Choice\n";
		}
	}while(c!=4);
	
}
