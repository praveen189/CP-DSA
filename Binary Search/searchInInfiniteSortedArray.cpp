#include<iostream>
#include<vector>

using namespace std;

int BS(vector<int> v,  int s, int e , int key){

    while (s<=e)
    {
        int mid = (s +(e-s)/2);

        if(v[mid] == key){
            return mid;
        }
        else if(v[mid] < key){
            s = mid +1;
        }else{
            e = mid-1;
        }
    }
    return -1;// if not found;
}
int main(){
    vector<int> v = {1,2,3,4,5,6,8,9,10,11,12,13};

    int key = 7;
    // search in infinte sorted array.

    int s = 0;
    int e = 1; // as we don't know about the high to locate.

    while(key > v[e] ){
        s = e;
        e = e*2;
    }
    // now we will get key bounded by s and e 
    // apply bs
    int index = BS(v, s, e, key);
    
    cout<<"Index of key "<<key<<" is: "<<index;
    return 0;
}