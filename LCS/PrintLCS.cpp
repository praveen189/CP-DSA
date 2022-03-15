#include<iostream>
#include<vector>
#include<bits/stdc++.h>


using namespace std;


void lcs(string &a, string &b, int m, int n){
    // 
    int t[10][10];

    // initialization 
    for(int j = 0;j<n+1; j++){
        for(int i = 0; i<n+1; i++){
            if(i == 0 || j == 0){
                t[i][j] = 0;
            }
        }
    }

    // choice diag
    for(int i = 1; i<m+1; i++){
        for(int j = 1; j<n+1; j++){
            if(a[i-1] == b[j-1]){
                t[i][j] = 1+ t[i-1][j-1];
            }
            else{
                t[i][j] = max( t[i-1][j], t[i][j-1] );
            }
        }
    }

    // now we have t matrix we have to backtrace this for the string
    string res;
    int i = m, j = n;
    // we will be tracking from the last index m,n.
    // bc : when we hits the any first column or row then we have to stop traversing as one ofstring will get empty
    while (i>0 && j >0)
    {
        if(a[i-1] == b[j-1]){
            // if last element matches 
            res.push_back(a[i-1]);
            i--;
            j--;
            // as we have filled this i, j with i-1, j-1 
        }
        else {
            // if not matches 
            if(t[i-1][j] > t[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }

    // now we have store the string in revered form 
    reverse(res.begin(), res.end());
    cout<<"Longest common subsequence: \n "<<res;
    
}
int main(){
    // print longest common subsequence 
    string a = "acbcf";
    string b = "abcdaf";

    int m = a.length();
    int n = b.length();

    lcs(a,b,m,n);

    cout<<"\nReturn to main back"<<endl;
    // now we have lcs where t-matrix have stored all values of match and mismatch 
    return 0;
}