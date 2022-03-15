// longest palindromic subsequence
#include<iostream>
#include<vector>
#include<bits/stdc++.h>


using namespace std;

string  lps(string a, int m){
    string b = a;
    reverse(a.begin(), a.end());

    int n = b.length();

    /*steps:
    1. find the length of longest subsequenc of lcs(a, reverse(a));
    */

    int t[m+1][n+1];

    for(int j = 0;j<n+1;j++){
        t[0][j] = 0;
    }
    for(int i = 0; i<m+1;i++){
        t[i][0] = 0;
    }

    // choice diag
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<m+1; j++){
            if(a[i-1] == b[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }

    // print lps
    //backtrack
    string res;
    int i = m, j = n;
    while(i > 0 && j >0){
        if(a[i-1] == b[j-1]){
            res.push_back(a[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i-1][j] > t[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    return res;

}

int main(){
    // find the length of longest palindromic subsequence 
    string a = "agbcba";

    int n = a.length();
    
    cout<<"length of longest palindromic subsequence:  "<<lps(a,n);

    return 0;
}