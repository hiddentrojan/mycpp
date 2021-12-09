#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

struct Class{
	int roll_no;
	string name;
	float sgpa;
};

void display(struct Class class_record[15])
{
	int i, len = 15;
	for(i=0;i<len;i++)
	{
		cout<<"\nRoll Number :"<<class_record[i].roll_no;
		cout<<"\nName :"<<class_record[i].name;
		cout<<"\nSGPA :"<<class_record[i].sgpa;
		cout<<"\n";
	}
	
}

void search(struct Class class_record[15])
{
	float s;
	int i, len=15;
	cout<<"Enter Your SGPA : ";
	cin>>s;
	cout<<"\nRollno.\tName"<<"\tSGPA\n";
	for(i=0;i<len;i++)
	{
		if(class_record[i].sgpa==s)
		{
			cout<<class_record[i].roll_no<<"\t"<<class_record[i].name<<"\t"<<class_record[i].sgpa<<"\n";
		}
	}
}

int main()
{
	struct Class class_record[15] = {
		{1, "Ak", 8.6},
		{2, "Vk", 9.4},
		{3, "Mk", 8.9},
		{4, "Pk", 8.9},
		{5, "Hk", 8.3},
		{6, "Nk", 9.5},
		{7, "Ok", 8.1},
		{8, "Ek", 8.9},
		{9, "Wk", 9.4},
		{10, "Qk", 8.9},
		{11, "Rk", 8.9},
		{12, "Yk", 9.4},
		{13, "Uk", 9.8},
		{14, "Bk", 9.1},
		{15, "Kk", 9.4}};
    display(class_record);
    search(class_record);
    return 0;
}
