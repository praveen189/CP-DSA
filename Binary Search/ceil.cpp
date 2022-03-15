#include<iostream>
#include<vector>

using namespace std;

int ceilFun(vector<int> v, int n , int key){
    // apply bs.

    int s = 0;
    int e = n-1;

    int res = -1;
// {1,2,3,4,5,6,7,8,9,10}
    while (s<=e)
    {
        int mid = (s + (e-s)/2);

        if(v[mid] == key){
            return v[mid];
        }
        else if(v[mid] < key){
           
            s = mid +1;
        }
        else if(v[mid] > key){
             res  = v[mid];
            e = mid-1;
        }
    }

    return res;
    
}
int main(){
    vector<int> v = {1,2,3,4,7,8,9,10};
    int key = 5;

    int n = v.size();

    int ceil = ceilFun(v, n, key);

    cout<<"Ceil of "<<key<<" is: "<<ceil<<endl;

    return 0;
}