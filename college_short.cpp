#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

struct Class{
	int roll_no;
	string name;
	float sgpa;
};

void display(struct Class class_record[], int n)
{
	int i, len = n;
	cout<<"\nRollno.\t\tName\t\tSGPA\n";
	for(i=0;i<len;i++)
	{
		cout<<class_record[i].roll_no<<"\t\t"<<class_record[i].name<<"\t\t"<<class_record[i].sgpa<<"\n";
	}
	
}

void search(struct Class class_record[], int n)
{
	float s;
	int i, len=n, flag=0;
	cout<<"\nEnter Your SGPA : ";
	cin>>s;
	cout<<"\nName"<<"\tSGPA\n";
	for(i=0;i<len;i++)
	{
		if(class_record[i].sgpa==s)
		{
			cout<<class_record[i].name<<"\t"<<class_record[i].sgpa<<"\n";
			flag=1;
		}
	}
	if(flag==0)
	{
		cout<<"No record found\n";
	}
}


void bsort(struct Class class_record[], int a)
{
	int i, j, n=a; 
    for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n-i-1; j++) 
		{
		 if (class_record[j].name>class_record[j+1].name) 
		 {
		  struct Class temp = class_record[j]; // int temp = x;
          class_record[j]=class_record[j+1]; // x=y;
          class_record[j+1]=temp; //y=temp;
          }
		}
         
	 }     
}

void bsearch(struct Class class_record[], int a)
{
	bsort(class_record, a);
	string t;
	cout<<"Enter the Name:";
	cin>>t;
	int low=0, n=a;
	int high=n-1;
	int si=-1;
	while (low<=high)
	{
		int mid=(low+high)/2;
		if(class_record[mid].name>t)
		{
			high = mid-1;
		}
		else if(class_record[mid].name==t)
		{
			si=mid;
			high= mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	
	int ei=-1;
	low=0;
	high=n-1;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(class_record[mid].name>t)
		{
			high=mid-1;
		}
		else if(class_record[mid].name==t)
		{
			ei=mid;
			low=mid+1;
		}
		else
		{
			low=mid+1;
		}
	}
	if(si!=-1 && ei!=-1)
	{
		cout<<"\nRollNo\t\tName\t\tSGPA\n";
		for(int i=si;i<=ei;i++)
		{
			cout<<class_record[i].roll_no<<"\t\t"<<class_record[i].name<<"\t\t"<<class_record[i].sgpa<<"\n";
		}
	}
}

void isort(struct Class class_record[], int a)
{
	int i, j, n=a;
	for(i=1;i<n;i++)
	{
		struct Class temp= class_record[i];
		j = i-1;
		while(j>=0 && temp.roll_no<class_record[j].roll_no)
		{
			class_record[j+1]=class_record[j];
			j--;
		}
		class_record[j+1]=temp;
	}
}

void qdisplay(struct Class class_record[])
{
	int len = 10;
	cout<<"\nRollno.\t\tName\t\tSGPA\n";
	for(int i=len-1;i>=0;i--)
	{
	 cout<<class_record[i].roll_no<<"\t\t"<<class_record[i].name<<"\t\t"<<class_record[i].sgpa<<"\n";
	}
}


void qsort(struct Class class_record[], int h, int l) // h is no. of elements and l is zero
{

	struct Class temp;
		
	if(l<h)
	{
	 int p= l; // pivot
	 int tbi = l+1; // toobigindex
	 int tsi = h; // toosmallindex
	 while(tsi>tbi)
	{
	 while(class_record[tbi].sgpa<=class_record[p].sgpa)
	 {
		++tbi;
	 }
	 
	 while(class_record[tsi].sgpa>class_record[p].sgpa)
	 {
		--tsi;
	 }
	
	 if(tbi<tsi)
	 {
		temp=class_record[tbi];
		class_record[tbi]=class_record[tsi];
		class_record[tsi]=temp;
	 }
	}
	
	temp=class_record[tsi];
	class_record[tsi]=class_record[p];
	class_record[p]=temp;
	
	qsort(class_record, tsi-1, p);
	qsort(class_record, h, tsi+1);
	}
}

int main()
{
	int n;
	cout<<"Enter the Number of Records to be entered : ";
	cin>>n;
	struct Class class_record[n];
	int i, c;
	
	do
	{
		cout<<"\n1]GetData\n2]Display\n3]Linear Search\n4]Bubble Sorted\n5]Binary Search\n6]Insertion Sort\n7]Quick Sort\n8]Exit\nEnter Your Choice : ";
	    cin>>c;
		switch(c)
		{
			case 1:
				cout<<"Enter the roll no. , name, sgpa : \n";
				for(i=0;i<n;i++)
				{
					cin>>class_record[i].roll_no>>class_record[i].name>>class_record[i].sgpa;
				}
				break;
			case 2:
				display(class_record, n);
				break;
			case 3:
				search(class_record, n);
				break;
			case 4:
				bsort(class_record, n);
				display(class_record, n);
				break;
			case 5:
				bsearch(class_record, n);
				break;
			case 6:
				isort(class_record, n);
				display(class_record, n);
				break;
			case 7:
				qsort(class_record, n-1, 0);
				qdisplay(class_record);
				break;
			case 8: exit;
			    break;
			default : cout<<"Wrong Choice";
				
		}
	}while(c!=8);
    return 0;
}
