#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;
void print(int arr[], int n){
    for(int i = 0;i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    // move all the negative element to left of array and positive to right
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = sizeof(arr)/sizeof(arr[0]);

    print(arr, n);
    // *** approach ***
    // use two pointer

    int l = 0; 
    int h = n-1;

    while(l <= h){
        if(arr[l] < 0 && arr[h] < 0 ){
            l++;
        }
        else if(arr[l] > 0 && arr[h] < 0){
            swap(arr[l] ,arr[h]);
            l++;
            h--;
        }
        else if(arr[l] > 0 && arr[h] > 0){
            h--;
        }
        else{
            l++;
            h--;
        }
    }

    // print
    print(arr, n);
    sort(arr, arr+n);
    print(arr,n);

    return 0;

}