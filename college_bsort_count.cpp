#include<iostream>

using namespace std;

void bsort(int a[], int n)
{
	int i, j, temp[n], count=0; 
    for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n-i-1; j++) 
		{
		 if (a[j]>a[j+1]) 
		 {
		  temp[i]=a[j]; // int temp = x;
          a[j]=a[j+1]; // x=y;
          a[j+1]=temp[i]; //y=temp;
          count+=1;
          }
		}
         
	 }
	 cout<<"\nNo. of Swapping done : "<<count;     
}

int main()
{
	int n;
	cout<<"Enter the Number of Elements : ";
	cin>>n;
	int a[n];
	cout<<"\nEnter the Elements : ";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	bsort(a, n);
}
