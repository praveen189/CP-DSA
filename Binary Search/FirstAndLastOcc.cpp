#include<iostream>
#include<vector>

using namespace std;

int lastOccIndex(vector<int> v, int n ,int key){
    int s = 0;
    int e = n-1;
    
    int res = -1; // if not found.

    while (s<=e)
    {
        int mid = (s + (e-s)/2);
        
        if(v[mid] == key){
            res = mid;
            s = mid +1;
        }
        else if(v[mid] < key){
            s = mid + 1;
        }
        else{
            e = mid -1;
        }
        
    }
    return res;
    
}
int firstOccIndex(vector<int> v, int n, int key){
    // apply bs
    int s = 0, e = n-1;
    int res = -1; // if not found.

    while (s<=e)
    {
        int mid = (s + (e-s)/2);

        if(v[mid] == key){
            res = mid;
            e = mid-1;
        }
        else if(v[mid] < key){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return res;


}

void printFun(vector<int> v, int n){
    for(int i = 0; i<n; i++){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){

    vector< int> v = {1,2,3,4,5,6,6,6,6,7,8,9};
    int n = v.size();
    int key = 6;

    printFun(v,n);

    for(int i = 0; i<n; i++){
        cout<<v[i]<<" ";
    }

    int firstOcc = firstOccIndex(v, n, key);
    cout<<"\nfirstOcc: "<<firstOcc<<endl;

    int lastOcc = lastOccIndex(v, n, key);
    cout<<"lastOcc: "<<lastOcc<<endl;

    // now count.
    if(firstOcc == -1){
        cout<<"no of occurance: "<<0<<endl;
    }else{
        cout<<"no of occurance: "<<(lastOcc - firstOcc +1)<<endl;

    }

    return 0;
}