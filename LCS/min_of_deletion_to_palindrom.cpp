#include<iostream>
#include<vector>
#include<bits/stdc++.h>


using namespace std;

int lps(string a, int m){
    string b = a;

    reverse(a.begin(), a.end());
    // we have to find the length of lcs

    // ** lcs **
    int n = b.length();

    int t[m][n];

    // initialization 
    for(int j = 0; j<n+1; j++){
        t[0][j] = 0;
    }
    for(int i = 0; i<m+1; i++){
        t[i][0] = 0;
    }

    // choice diag
    for(int i = 1; i<m+1; i++){
        for(int j = 1; j<n+1; j++){
            if(a[i- 1] == b[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j] , t[i][j-1]);
            }
        }
    }
    return t[m][n];
    

}
int main(){
    // find the min of deletion to make a string a palindrom
    string a = "agbcba";

    // ****approach****
    /*1. find the lps (longest common subsequence )
    2. then the min of deletion is length of a - lps(a, revers(a));
    */
   int lpsLength = lps(a, a.length());
   int minOfDeletion = a.length() - lpsLength;
   cout<<"minimum no of deletion: "<< minOfDeletion<<endl;

   return  0;



}