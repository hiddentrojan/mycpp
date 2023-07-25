//Selection Sort in CPP

#include<iostream>
using namespace std;

int main(){

    int arr[5] = {7,5,11,4,2};

    for(int i = 0; i<5; i++){

        for(int j=i+1; j<5; j++){

            if(arr[j] < arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }

        }

    }

    //Output
    for(int i = 0; i<5; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}