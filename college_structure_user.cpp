#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

struct employee{
	string name;
	int id;
	float salary;
	};
void display(struct employee e1)
{
	cout<<"Name Of The Employee : "<<e1.name<<"\n";
	cout<<"Employee ID : "<<e1.id<<"\n";
	cout<<"Salary :$ "<<e1.salary<<"\n";
}

int main ()
{
    struct employee e1;
	cout<<"Enter The Name of The Employee : ";
	cin>>e1.name;
	cout<<"Enter The Employee ID : ";
	cin>>e1.id;
	cout<<"Enter The Salary :";
	cin>>e1.salary;
	cout<<"--------------------------------\n";
	display(e1);
	return 0;
}
