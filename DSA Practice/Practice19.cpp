#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string n, t="", a="";
    cin>>n;
    int l = n.length();
    //cout<<l;
    string c[l];
    int j = 0;
    //cout<<n;
    for(int i=0;i<l;i++){
        c[i] = "0";
    }
    for(int i=0;i<=l;i++){
        t=n[i];
        //cout<<t<<"\n";
        if(t==","){
            //cout<<a<<"\n";
            //cout<<j<<"\n";
            c[j] = a;
            //cout<<c[j]<<"\n";
            a = "";
            //cout<<a<<"\n";
            j++;
        }
        else{
            a+=t;
            //cout<<a<<"\n";  
        }
    }
    /*for(int i=0;i<l;i++){
        cout<<c[i]<<"\n";
        if(c[i]!="0"){
            cout<<c[i]<<"\n";
        }
    }*/
    return 0;
}
