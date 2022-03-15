#include<iostream>
#include<vector>

using namespace std;
int indexOFSmallestEleFun(vector<int> v, int n){
    int s = 0;
    int e = n-1;

    while (s<=e)
    {
        int mid = (s + (e-s)/2);

        int next = (mid +1)%n;
        int prev = (mid + n -1)%n;

        if((v[mid]<= v[next]) && (v[mid] <=v[prev])){
            return mid;
        }else if (v[0] <= v[mid])
        {
            // left part is sorted so move s to mid + 1
            s = mid +1;
        }else if(v[mid] <= v[n-1]){
            e = mid -1;
        }
        
    }
    return -1;
    
}

int SearchBS(vector<int> v, int s, int e, int key){
    while (s<=e)
    {
        int mid = (s + (e-s)/2);

        if(v[mid] == key){
            return mid;
        }else if(v[mid] < key){
            s = mid +1;
        }else{
            e = mid -1;
        }
    }
    return -1;
}
int main(){

    vector<int> v = {11,12,14,16,18,2,3,7,8,9};
    int n = v.size();
    int key = 18;

    // find index of key.
    // 1. find the index of smallest ele.



    int indexOFSmallestEle = indexOFSmallestEleFun(v,n);

    cout<<"index of min ele: "<<indexOFSmallestEle<<endl;

    int leftSearch = SearchBS(v, 0, indexOFSmallestEle-1, key);
    int rightSearch = SearchBS(v, indexOFSmallestEle, n-1,key);

    if(leftSearch == -1){
        cout<<"index of key 12 is: "<<rightSearch<<endl;
    }else{
        cout<<"index of key 12 is : "<<leftSearch<<endl;
    }
    


    return 0;

}