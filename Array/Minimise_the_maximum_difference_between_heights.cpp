#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(int arr[], int n, int k){
    //
    sort(arr, arr+n);

    int mn, mx;

    int res = arr[n-1] - arr[0];

    /*
    for(int i = 1; i<n ;i++){
        if(arr[i]  >= k){
            int mn = min(arr[i] - k, arr[0]+k);
            int mx = max(arr[i-1]+k, arr[n-1]-k)
        }
    }*/

    for(int i = 1; i<n; i++){
        if(arr[i] >= k){
            mx = max(arr[i-1] + k, arr[n-1]-k);
            mn = min(arr[0] + k, arr[i] -k);

            res = min(res, (mx - mn));
        }
    }
    return res;
    
}
int main(){
    int arr[] = {3, 9, 12, 16, 20};
    int k = 3;

    int n = sizeof(arr)/sizeof(arr[0]);

    int ans = solve(arr, n,k);

    cout<<"Min diff btw the max and min: "<<ans;

    return 0;


}