#include<iostream>
#include<vector>

using namespace std;

int lcs(string a, string b, int m, int n){
    // return lcs length
    int t[m+1][n+1];
    // initialization 
    for(int j = 0; j<n+1; j++){
        t[0][j] = 0;
    }
    for(int i = 0;i<m+1; i++){
        t[i][0] = 0;
    }

    //choice diag 
    for(int i = 1; i<m+1; i++){
        for(int j = 1; j<n+1; j++){
            if(a[i-1] == b[j-1]){
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
    // shortes common supersequence length
    string a = "aggtab";
    string b = "gxtxayb";

    // op - aggxtxayb 
    // lcs --- gtab
    //
    // *** approach *** 
    /*1. find the lcs 
    2. then wirte all those letter which are not common and for common use one whihch is counted in _List_const_iterator
    // return (a + b -lcs(a,b));
    */

   int lenLcs = lcs(a,b, a.length(), b.length());
   int res= (a.length() + b.length() - lenLcs);
   cout<<"length of shortes common super sequence: "<<res;

   return 0;


}