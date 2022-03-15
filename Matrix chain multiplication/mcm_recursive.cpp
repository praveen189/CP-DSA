#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int i, int j){
    // 2. bc
    if(i >= j){
        return 0; // for i == j this will have only one ele so not partition will be possible 
    }

    // move k form i to j

    int mn = INT_MAX;
    for(int k = i; k<=j-1; k++){
        int temp = ( solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1] * arr[k] * arr[j]);

        if(mn > temp){
            mn = temp;
        }
    }

    return mn;

}

int main(){
    // find the min cost or min # of multiplication of mcm
    int arr[] = {40,20,30,10,30};

    int n = sizeof(arr)/sizeof(arr[0]);

    // steps
    /*1. find i and j
    2. find bc
    3. move k to (i --- j)
    4. cal. ans form temp ans
    */

   /*Ai = Ai-1 * Ai
   like A1 = A0 * A1 
   1. islye i = 1 not 0

   2. for j 
   j = n-1 
   A5 = A4 * A5// possible 

   */

   int i = 1;
   int j = n-1;
   int ans = solve(arr, i, j);
   cout<<"min # of multiplication: "<<ans<<endl;

   return 0;


}