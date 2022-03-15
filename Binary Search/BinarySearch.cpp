#include<iostream>
#include<vector>

using namespace std;

int findSearch(vector<int> v, int key, int n){
    int s = 0 ;
    int e = n-1;

    while (s<=e)
    {
        int mid  = ( s + (e-s)/2);

        if(v[mid] == key){
            return mid;
        }else if(v[mid] < key){
            s = mid + 1;
        }else{
            e = mid -1;
        }
    }
    return -1; // if not found.
    
}

int main(){

    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    int key = 2;
    int n = v.size();

    int index = findSearch(v, key, n);

    for(int i = 0; i<n; i++){
        cout<<i<<"  ";
    }
    
    cout<<endl;
    
    for(int i = 0; i<n; i++){
        cout<<v[i]<<" ";
    }
    
    cout<<endl;
    cout<<"Index of ele: "<<index<<endl;

    return 0;
}