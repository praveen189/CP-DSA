#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int CountSubSetDiffFun(vector<int> &arr, int n, int sum){
    int t[n+1][sum+1];

    for(int j = 0; j<sum+1; j++){
        t[0][j] = 0;
    }
    for(int i = 0; i<n+1; i++){
        t[i][0] = 1;
    }

    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<sum+1; j++){
            if(arr[i-1] <= j){
                // lo ye na lo
                t[i][j] = ( ( t[i-1][j-arr[i-1]]) + t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][sum];


}
int main(){
    // count the no. of subset with given sum by changing the sign ie. +/- .
    // s1 - s2 = sum
    // **** parent question is count sub set sum with given sum = (range + diff)/2
    vector<int> arr = {1,1,2,3};
    int sum =1;

    int n = arr.size();

    int range = 0;
    for(int i = 0; i<n; i++){
        range += arr[i];
    }

    // **** parent question is count sub set sum with given sum = (range + diff)/2
    sum = (range + sum)/2;

    int res = CountSubSetDiffFun(arr, n, sum);
    cout<<"Count of no. of sub set with diff: "<<res;
    

    return 0;

}