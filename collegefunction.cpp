#include <iostream>

using namespace std;

void getdata(int b[], int num) //formal parameter
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
            cout<<"Element Present At Position "<<i+1; // 1 2 3 4 5 6
            										// 0 1 2 3 4 5
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
	int a[n];// actual parmeter
	cout<<"Enter The Number Of Element : ";
    cin>>n;
    getdata(a, n); //functionname();
    display(a, n);
    search(a, n);
    return 0;
}
