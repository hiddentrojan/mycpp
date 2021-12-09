#include <iostream>
#include <stdio.h>
#include <string>

using namespace std; //name, id, salary

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
	struct employee e1 = {"Jacky", 1011, 12700};
	display(e1);
	return 0;
}
