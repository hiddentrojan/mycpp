#include <iostream>

using namespace std;

void getdata(int b[], int num)
{
	 cout<<"Enter the elements : ";
    for(int i=0;i<num;i++)
    {
        cin>>b[i];
    }
}

void display(int b[], int num)
{
     cout<<"Elements are ";
	for(int i=0;i<num;i++)
    {
        cout<<"\t"<<b[i];
    }
}

void search(int b[], int num)
{
	int item;
	cout<<"\nEnter The Element to be searched : ";
    cin>>item;
    int flag=0;
    for(int i=0;i<num;i++)
    {
        if(b[i]==item)
        {
            cout<<"Element Present At Position "<<i+1;
            flag=1;
            break;
        }
    }
    if(flag==0)
    cout<<"Element not found";
}

int main()
{
	int n;
	int a[n];
	int c;
	cout<<"Enter The Number Of Element : ";
    cin>>n;
    do
    {
	cout<<"\n1] Get Data \n 2] Display \n 3] Search \n 4] Exit \n Enter Your Choice : ";
	cin>>c;
	
	switch (c)
	 {
		case 1 :getdata(a, n);
	 break;
	 case 2 :display(a, n);
	 break;
	 case 3:search(a, n);
	 break;
	 case 4: exit;
	 break;
	 default : cout<<"Wrong Choice";
	 	break;
	 }
    }while(c!=4);
}

