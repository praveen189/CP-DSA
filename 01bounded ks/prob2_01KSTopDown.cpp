#include<iostream>
#include<vector>

using namespace std;
int ksTopDown(vector<int> &wt, vector<int> &val, int n , int w ){
    // / initialization 
    int t[n+1][w+1];
    for(int i = 0; i<n+1; i++){
        t[i][0] = 0;
    }
    for(int j = 0; j<w+1; j++){
        t[0][j] = 0;
    }
    //code
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<w+1; j++){
            // two case
            if(wt[i-1] <= j){
                // lo ye na lo
                t[i][j]= max( (val[i-1] + t[i-1][j-wt[i-1]]), t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][w];
}
int main(){
    // prob2 - 01 ks top down 
    vector<int> wt = {10, 20, 30};
    vector<int> val = {60, 200, 120};
    int w = 50;; // capacity of ks in kg

    int n = wt.size();
    cout<<"max profit: "<<ksTopDown(wt, val, n, w);

    return 0;
}
