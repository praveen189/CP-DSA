#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void print (int arr[], int n){
    for (int  i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    
}
int bs(int arr[], int n, int key){
    // bs
    sort(arr, arr+n);
    print(arr,n);
    int s = 0;
    int e = n-1;

    while (s <= e)
    {
        int mid = (s + (e-s)/2);

        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            e = mid-1;
        }
        else{
            s = mid +1;
        }
    }
    return -1; //  not found 

}

int main()
{
    // linar search
    int arr[] = {3, 2, 5, 7, 91, 1};
    int key = 3;

    // o/p: index if found ohterwise -1;
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout<<"before sort\n"<<print(arr,n);
    print(arr,n);
    
    cout << "index of key: " << key << "is: " << bs(arr, n, key);

    return 0;
}