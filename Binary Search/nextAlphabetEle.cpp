#include<iostream>
#include<vector>

using namespace std;
char ceilOfKeyFun(vector<char> v, int n, int key){
    int s = 0;
    int e = n-1;

    char res ='#';


    while (s<=e)
    {
        int mid = (s+ (e-s)/2);

        if(v[mid] == key){
            s = mid +1;
        }else if(v[mid] < key){

            s = mid +1;
        }else if(v[mid] > key){
            res = v[mid]; 
            // ceil : is the smallest element greater to key.
            e = mid -1;
        }
    }
    return res;

}


int main(){

    vector<char> v = {'a', 'c', 'f', 'h'};
    char key  = 'i';

    int n = v.size();

    char ceilOfKey = ceilOfKeyFun(v, n, key);

    cout<<"Next alphabet found at: "<<ceilOfKey<<endl;
    return 0;
}