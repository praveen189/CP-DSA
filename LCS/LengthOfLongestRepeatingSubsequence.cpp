#include<iostream>
#include<vector>

using namespace std;

void lrs(string a, string b, int m, int n){
    // complete the t matrix with restriction that i != j
    int t[m+1][n+1];

    for(int j = 0; j<n+1; j++){
        t[0][j] = 0;
    }
    for(int i = 0;i<m+1; i++){
        t[i][0] = 0;
    }

    // choice diag
    for(int i = 1; i<m+1; i++){
        for(int j = 1; j<n+1; j++){
            if(a[i-1] == b[j-1] && i != j){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j] , t[i][j-1]);
            }
        }
    }

    cout<<"Length of longest repeating sequence:"<<t[m][n];
    
}

int main(){
    // find the length of longest  repeating sub sequence 
    string  a = "aabebcdd";

    // approach
    /*1. create another string b = a
    then find the lcs and you will observe that the element which have same index in two string is not taken in the lognet common repeating subsequence
    */

    string b = a;
    lrs(a,b, a.length(), b.length());

    return 0; 
}