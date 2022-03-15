#include<iostream>
#include<vector>

using namespace std;

int findSearch(vector<int> v, int key, int n){
    int s = 0 ;
    int e = n-1;
// {20, 18, 16, 15, 13,9,7,4,3,2};
    while (s<=e)
    {
        int mid  = ( s + (e-s)/2);

        if(v[mid] == key){
            return mid;
        }else if(v[mid] < key){
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }
    return -1; // if not found.
    
}

int main(){

    vector<int> v = {20, 18, 16, 15, 13,9,7,4,3,2};
    int key = 41;
    int n = v.size();

    int index = findSearch(v, key, n);

    for(int i = 0; i<n; i++){
        cout<<i<<" ";
    }
    
    cout<<endl;
    
    for(int i = 0; i<n; i++){
        cout<<v[i]<<" ";
    }
    
    cout<<endl;
    cout<<"Index of ele: "<<index<<endl;

    return 0;
}