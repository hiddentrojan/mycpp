#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

struct employee{
	string name[10];
	int id[10];
	float salary[10];
	};
void display(struct employee e1)
{
	cout<<"SrNo.\t Employee Name \t Employee ID \t Salary \n";
	for(int i=0;i<10;i++)
	{
			cout<<i+1<<"\t \t"<<e1.name[i]<<"\t \t"<<e1.id[i]<<"\t \t"<<e1.salary[i]<<"\n";
	}
}

int main ()
{
    struct employee e1;
    int i;
    cout<<"Enter The Name of The Employee in Sequence : ";
    for(i=0;i<10;i++)
    {
	  cin>>e1.name[i];
	}
	cout<<"--------------------------------\n";
	cout<<"Enter The Employee ID in Sequence : ";
	for(i=0;i<10;i++)
	{
		cin>>e1.id[i];
	}
	cout<<"--------------------------------\n";
	cout<<"Enter The Salary in Sequence:";
	for(i=0;i<10;i++)
	{
		cin>>e1.salary[i];
	}
	cout<<"--------------------------------\n";
	display(e1);
	return 0;
}
