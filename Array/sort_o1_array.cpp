#include<iostream>

using namespace std;

void print(int arr[], int n){
    for(int i = 0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    // sort the 0 and 1 in an array
    int arr[] = {0,1,0,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    print(arr,n);
    

    //method -2;
    // use two pointer 
    int i = 0;
    int j = n-1;
    while(i <= j){
        if(arr[i] == 1){
            swap(arr[i], arr[j]);
            j--;
            // as 1 is at its corret position 

        }
        else{
            i++; // we have 0 at ith index
        }
    }

    print(arr, n);

    
    
    // method -1 
    //count the 0 and find n-count of zeros and put into the is_array
    

    /*
    int noOfZeros = 0;
    for(int i = 0; i<n; i++){
        if(arr[i]  == 0){
            noOfZeros++;
        }
    }
    int noOFOnes = n- noOfZeros;

    for(int i = 0; i<noOfZeros; i++){
        arr[i] = 0;
    }
    for(int i = noOfZeros; i<noOFOnes; i++){
        arr[i] = 1;
    }

    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    */
    return 0;

}