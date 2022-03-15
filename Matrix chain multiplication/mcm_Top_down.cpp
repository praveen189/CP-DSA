#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int t[10][10];

int solve(int arr[], int i, int j){
    // bc 
    if(i >= j){
        return 0;
    }

    // 
    if(t[i][j] != -1){
        return t[i][j];
    }

    // move k form i to j
    int mn = INT_MAX;
    for(int k = i; k<= j-1; k++){
        int temp = ( solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j] );

        if(mn > temp){
            mn = temp;
        }
    }
    return t[i][j] = mn;

 
}

int main(){
    // mcm bottom up 
    int arr[] = { 10, 30, 5, 60};

    int n = sizeof(arr)/sizeof(arr[0]);

    int i =1;
    int j = n-1;

    // memset for -1 
    memset(t, -1 , sizeof(t));

    int ans = solve(arr, i, j);
    cout<<"Min # of mcm: multiplication: "<<ans<<endl;

    return 0;



}