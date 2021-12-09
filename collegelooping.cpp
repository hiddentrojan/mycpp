#include<iostream>

using namespace std;

void search(int n)
{
    int array[n],i,item;
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
    int u=1;
	 do{
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
    cout<<"Do You Want To Continue?? Yes(1) or No(0)";
    cin>>u;
     }while(u!=0)

int main(void)
{
	int num;
    cout<<"Enter The Number Of Element";
    cin>>num;
    int s = search(num);
    return 0;
}
