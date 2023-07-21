#include<iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter number the number of stars you want :";
    cin>>n;

    for(int i = n-1; i>=0; i--){
        for(int j = 0;j<n-i;j++){
            cout<<" * ";
        }
        cout<<" \n ";
    }

    return 0;
};