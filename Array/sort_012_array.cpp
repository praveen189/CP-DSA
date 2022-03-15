#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void print(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    // sort 0,1,2,in an array.
    int arr[] = {0,1,1,1,0,0,2,2,1,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    print(arr, n);
    //method -1 
    // sort the arry
    //TC - O(nlog(n))
    sort(arr, arr+n);
    print(arr, n);

    // method -2
    //count 0, 1,2, and then fill in the array
    // TC - O(n) + O(N) = o(2N) : first O(n): count ,sec O(n) for filling it 

    // method -3
    // use tree pointer 
    int s = 0;
    int m = 0;
    int e = n-1;

    while(m <= e){
        if(arr[m] == 0){
            swap(arr[s], arr[m]);
            s++;
            m++;
        }
        else if(arr[m] == 1){
            m++;
        }
        else if(arr[m] == 2){
            swap(arr[m], arr[e]);
            e--;
        }
    }

    
    cout<<"3 pointer method: "<<endl;
    print(arr, n);
    



}