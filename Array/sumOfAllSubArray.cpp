#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void subSetSum(int arr[], int n){
    int ans = 0;
        // int arr[] = {1,2,3,4};
    for(int i = 0; i<n; i++){
        int curr = 0;
        for (int  j = i; j < n; j++)
        {
            curr += arr[j];
            cout<<curr<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    // linar search
    int arr[] = {1,2,3,4};
    // sub array: continuous:
    // 1, 12,123,1234, 2,23,234,3,34,4 :: sum of all sub array

    //O/P:: sum of alll subarray
    int n = sizeof(arr)/sizeof(arr[0]); 
    subSetSum(arr, n);


    return 0;
}