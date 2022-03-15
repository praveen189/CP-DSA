#include<iostream>
#include<vector>

using namespace std;

bool equalPartitionFun(vector<int> &arr, int n, int sum){
    int t[n+1][sum+1];

    // initialization
    for(int i = 0; i<n+1; i++){
        t[i][0] = true;
    }
    for(int j = 0; j<sum+1; j++){
        t[0][j] = false;
    }

    // code
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<sum+1; j++){
            if(arr[i-1] <= j){
                t[i][j] = ( (t[i-1][j-arr[i-1]]) || (t[i-1][j]) );
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][sum];

}

int main(){
    // prob-4: equal sum partion prob return if exist t/f
    vector<int> arr = {1,2,4,4,5,5};
    int n = arr.size();

    int sum = 0;

    for(int i = 0; i<n; i++){
        sum +=arr[i];
    }

    if(sum%2 != 0){
        // odd sum can't be divided into two equal subset.
        cout<<"not possible: "<<false;
    }
    else{
        cout<<equalPartitionFun(arr, n, sum/2);
    }


    return 0;
    

}