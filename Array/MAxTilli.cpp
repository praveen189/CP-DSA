#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void maxTilli(int arr[], int n){
    int maxTillNow = INT_MIN;
    for(int i = 0; i<n; i++){
        maxTillNow = max(arr[i], maxTillNow);
        cout<<maxTillNow<<" ";
    }
    cout<<endl;
}
int main()
{
    // linar search
    int arr[] = {3, 2, 5, 7, 91, 1};

    // o/p: index if found ohterwise -1;
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << "index of key: " << key << "is: " << linearSearch(arr, n, key);
    maxTilli(arr,n);

    return 0;
}