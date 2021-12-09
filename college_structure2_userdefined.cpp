#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

struct Class{
	int roll_no;
	string name;
	float sgpa;
};

void display(struct Class class_record[5])
{
	int i, len = 5;
	cout<<"\nRollno.\t\tName\t\tSGPA\n";
	for(i=0;i<len;i++)
	{
		cout<<class_record[i].roll_no<<"\t\t"<<class_record[i].name<<"\t\t"<<class_record[i].sgpa<<"\n";
	}
	
}

void search(struct Class class_record[5])
{
	float s;
	int i, len=5;
	cout<<"\nEnter Your SGPA : ";
	cin>>s;
	cout<<"\nName"<<"\tSGPA\n";
	for(i=0;i<len;i++)
	{
		if(class_record[i].sgpa==s)
		{
			cout<<class_record[i].name<<"\t"<<class_record[i].sgpa<<"\n";
		}
	}
}

int main()
{
	struct Class class_record[5];
	int i, c;
	
	do
	{
		cout<<"\n1]GetData\n2]Display\n3]Search\n4]Exit\nEnter Your Choice : ";
	    cin>>c;
		switch(c)
		{
			case 1:
				cout<<"Enter the roll no. , name, sgpa : \n";
				for(i=0;i<5;i++)
				{
					cin>>class_record[i].roll_no>>class_record[i].name>>class_record[i].sgpa;
				}
				break;
			case 2:
				display(class_record);
				break;
			case 3:
				search(class_record);
				break;
			case 4: exit(0);
			    break;
			default : cout<<"Wrong Choice";
				
		}
	}while(c!=4);
    return 0;
}
