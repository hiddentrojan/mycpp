#include<iostream>

using namespace std;

int main(){
    int n;

    cout<<"Number : ";
    cin>>n;

    if(n%2!=0 && n!=0 && n!=1){
        cout<<n<<" is a Prime Number";
    }
    else{
        cout<<n<<" is not a Prime Number";
    }
}