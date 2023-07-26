#include<iostream>

using namespace std;

int main(){
    string n, temp;
    int count = 0;
    cout<<" Input  : ";
    cin>>n;
    int l = n.length();
    for(int i=0;i<=l;i++){
        temp = n[i];
        for(int j=i+1;j<=l;j++){
            if(n[i]==n[j]){
                count++;
                break;
            }
        }
    }
    cout<<" Output :"<<count;
    return 0;
}