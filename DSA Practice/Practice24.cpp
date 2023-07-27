#include<iostream>

using namespace std;

void bsort(int a[], int n)
{
	int i, j, temp[n]; 
    for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n-i-1; j++) 
		{
		 if (a[j]>a[j+1]) 
		 {
		  temp[i]=a[j]; // int temp = x;
          a[j]=a[j+1]; // x=y;
          a[j+1]=temp[i]; //y=temp;
          }
		}
         
	}

    cout<<"Second Largest Number in the array is "<<a[n-2];
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	bsort(a, n);
}
