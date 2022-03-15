#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int arr[] = {3,1,3,4,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    sort(arr, arr+n);

    /*for(int i = 0; i<n; i++){
        if(arr[i] != i+1){
            cout<<"Duplicate: "<<arr[i];
            break;
        }
    }
    */

   //**** approach 2
//    sort h to duplicates will occure at neighbour hood of each other
for(int i = 0; i<n; i++){
    if(arr[i] == arr[i+1]){
        cout<<"duplicates: "<<arr[i];
    }
}
    return 0;

}