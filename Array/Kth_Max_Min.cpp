#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void print(int arr[], int n){
    for(int i = 0;i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    // find the kth smallest ele
    int arr[] = {5,2,3,4,1};
    int k = 2;

    int n = sizeof(arr)/sizeof(arr[0]);

    print(arr, n);

    sort(arr, arr+n);

    print(arr, n);

    cout<<"\n Kth smallest ele: "<<arr[k-1];
    cout<<"\n Kth max ele: "<<arr[n-k];
    return 0;
}