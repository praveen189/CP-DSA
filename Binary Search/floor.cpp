#include<iostream>
#include<vector>

using namespace std;

int floorFun(vector<int> v, int n, int  key){
    // apply bs.

    int s = 0;
    int e = n-1;

    int res = -1;
    while (s<=e)
    {
        int mid = (s + (e-s)/2);

        if(v[mid] == key){
            return v[mid];
        }
        else if(v[mid] < key){
            res = v[mid];
            s= mid +1;
        }else if(v[mid] > key){
            e= mid-1;
        }
    }
    return res;
    

}
int main(){

    vector<int> v = {1,2,3,4,6,7,8,9};
    int key = 5;

    int n = v.size();

    int floor = floorFun(v,n,key);

    cout<<"floor of "<<key<<"is: "<<floor<<endl;
    return 0;
}