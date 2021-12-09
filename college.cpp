#include<iostream>

using namespace std;

int main()
{
    int n; //variable 
    cout<<"Enter The Number Of Element"; // 10
    cin>>n;
    int array[n],i,item; // 0 1 2 3 4
    cout<<"Enter the elements";
    for(i=0;i<n;i++)
    {
        cin>>array[i]; 
    }
    cout<<"Elements are ";
	for(i=0;i<n;i++)
    {
        cout<<"\t"<<array[i];
    }
    cout<<"\nEnter The Element to be searched";
    cin>>item;
    int flag=0;
    for(i=0;i<n;i++)
    {
        if(array[i]==item)
        {
            cout<<"Element Present At Position"<<i+1;
            flag=1;
            break;
        }
    }
    if(flag==0)
    cout<<"Element not found";  
}
