#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

void print(vector<int>arr, int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    // reverse the array
    vector<int> arr = {1,2,3,4,5};

    // int n = sizeof(arr)/sizeof(arr[0]);
    int n = arr.size();

    print(arr,n);

    int s = 0;
    int e = n-1;

    while(s <= e){
        swap(arr[s] , arr[e]);
        s++;
        e--;
    }

    print(arr,n);
    reverse(arr.begin(), arr.end());
    print(arr,n);


    return 0;


}