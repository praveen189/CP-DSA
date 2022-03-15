#include<iostream>
#include<vector>

using namespace std;

int indexOfEle(vector<int> v, int n){
    // use bs.
    int s = 0;
    int e = n-1;

    while (s<=e)
    {
        int mid = (s + (e-s)/2);

        int next = (mid + 1)%n;
        int prev = (mid + n -1)%n;

        if((v[mid] <= v[next]) && (v[mid] <=v[prev])){
            return mid;
        }
        else if(v[0] <= v[mid]){
            s = mid +1;
        }
        // else{
        //     e = mid;
        // }
        else if(v[mid] <= v[n-1]){
            e= mid -1;
        }
    }
    return -1;
}

int main(){

    vector<int> v = {11,12,18,20,21,34, 45,1,2,3,4,6,8};
    int n = v.size();

    // index of min ele.
    int index = indexOfEle(v,n);
    cout<<"Index of min ele: "<<index<<endl;

    return 0;
}