#include<iostream>
#include <bits/stdc++.h>

using namespace std;

class myfirstclass
{
	
	private : int i, item, a[10];
	
	public :
		
	void getdata(int n)
	{
	 cout<<"Enter the elements : ";
    for(i=0;i<n;i++)
    {
        cin>>a[i]; // 0 1 2 3 4
    }
	}

	void display(int n)
	{
     cout<<"Elements are ";
	for(i=0;i<n;i++)
    {
        cout<<"\t"<<a[i];
    }
	}

	void search(int n)
	{
	cout<<"\nEnter The Element to be searched : ";
    cin>>item;
    int flag=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==item)
        {
            cout<<"Element Present At Position "<<i+1<<"\n";
            flag=1;
            break;
        }
    }
    if(flag==0)
    cout<<"Element not found";
	}
};

int main()
{	
    int nu;
    cout<<"Enter The Number of elements : ";
	cin>>nu;
	myfirstclass obj1; //classname objectname;
	int c; 
	do
    {
	cout<<"\n 1] Get Data \n 2] Display \n 3] Search \n 4] Exit \n Enter Your Choice : ";
	cin>>c;
	
	switch (c)
	 {
	 case 1 : obj1.getdata(nu);// objectname.getdata(parameter*);
	 break;
	 case 2 :obj1.display(nu);
	 break;
	 case 3:obj1.search(nu);
	 break;
	 case 4: exit;
	 break;
	 default : cout<<"Wrong Choice";
	 break;
	 }
    }while(c!=4);
    return 0; 
}

