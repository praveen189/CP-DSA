#include<iostream>
#include<vector>

using namespace std;
void lcs(string a, string b, int m, int n){
    int t[m+1][n+1];

    // initialization 
    for (int  j = 0; j <m+1; j++)
    {
        t[0][j] = 0;
    }
    
    for(int i = 0; i<n+1; i++){
        t[i][0] = 0;
    }

    // choice diag.
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

    // print lcs
    // backtrack form m ,n

    string res; 
    int i = m , j = n;
    while(i > 0 && j > 0){
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

    cout<<"longest common subsequence: "<<res<<"\n lcs: "<<res.length()<<endl;
    // return 0;
}

int main(){
    // find the length of longest common subsequence 
    string a = "agbcba";
    string b = "abcbga";

    int m = a.length();
    int n = b.length();

    // cout<<"Lcs: "<<lcs(a,b,m,n);
    lcs(a,b,m,n);
    
    return 0;
}