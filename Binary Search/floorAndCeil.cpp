#include<iostream>
#include<vector>
using namespace std;

pair<int, int> floorFun(vector<int> v, int n, int key){

    int s = 0;
    int e = n-1;

    int resFloor = -1;
    int resCeil = -1;  // if not found 
    // {1,2,3,4,6,7,8,9}
    while (s<=e)
    {
        int mid = (s + (e-s)/2);
        
        if(v[mid] == key){
            resCeil = resFloor = v[mid];
            break;
        }
        else if(v[mid] < key){
             resFloor = v[mid]; 
            s= mid +1;
        }
        else if(v[mid] > key){
            resCeil = v[mid];
             // all bigger elemet will be our candidates.
            e = mid -1;
        }
    }
    pair<int, int> p = {resFloor, resCeil};

    return p;

}

int main(){

    // vector<int> v = {1,2,3,4,6,7,8,9};
    // int key = 5;

    vector<int> v = {1,2,4,5,6,8,10,15};
    int key = 12;

    int n = v.size();

    pair<int, int> p = floorFun(v,n, key);

    cout<<"Floor of "<<key<<" is: "<<p.first<<endl;
    cout<<"Ceil of "<<key<<" is: "<<p.second<<endl;
    
    return  0;
}