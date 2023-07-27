#include<iostream>

using namespace std;

int main(){

    int n; //variable initialization
    
    cout<<"Size of the List : ";
    cin>>n; // Size

    int arr[n], avg = 0; //variable initialization

    cout<<"Input : ";

    for(int i=0;i<n;i++){
        cin>>arr[i]; // Input in the array
        avg+=arr[i];
    }
    avg/=n;

    cout<<"Average is ";
    cout<<avg;

}