#include<iostream>

using namespace std;

int main(){
    string n;
    cin>>n;

    int l = n.length();

    string mat[l][2];

    int count = 0;

    for(int i=0;i<l;i++){
        string temp = n[i];
        mat[i][1] = temp;
        for(int j=i+1;j<l;i++){
            string temp2 = mat[i][1];
            if(temp==n[j] && temp!=temp2){
                count+=1;
                mat[i][2]=count;
            }
        }
        count = 0;
    }

    cout<<"\n";

    for(int i=0;i<l;i++){
        cout<<mat[i][1]<<" : "<<mat[i][2]<<"\n";
    }
}