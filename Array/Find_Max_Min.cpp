#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

void print(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    // reverse the array
    int arr[] = {1,2,3,4,5};

    // int n = sizeof(arr)/sizeof(arr[0]);
    // int n = arr.size();
    int n = sizeof(arr)/sizeof(arr[0]);


    print(arr,n);

    int maxi = *max_element(arr, arr+n);
    int mini = *min_element(arr, arr+n);
    cout<<maxi<<"\n"<<mini<<endl;




    return 0;


}