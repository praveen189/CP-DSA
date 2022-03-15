#include<iostream>
#include<vector>
#include<bits/stdc++.h>


using namespace std;

void printScs(string a, string b, int m, int n){
    // first t - matrix
    // backtrack all the ele
    // if matches add
    // if not matches then add the max (val wala)

    int t[m+1][n+1];
    for(int j = 0; j<n+1; j++){
        t[0][j] = 0;
    }
    for (int  i = 0; i < m+1; i++)
    {
        t[i][0] = 0;
    }

    // choice diag
    for(int i = 1; i<m+1; i++){
        for(int j = 1; j<n+1; j++){
            if(a[i-1] == b[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    
    // now backtrack
    
    int i = m, j = n;
    
    cout<<"Check 1: "<<m <<n<<endl;
    string res = "";

    while (i>0 && j >0){
        if(a[i-1] == b[j-1]){
            res.push_back(a[i-1]);
            i--;
            j--;

        }
        else{
            if(t[i-1][j] > t[i][j-1]){
                res.push_back(a[i-1]);
                i--;
            }
            else{
                res.push_back(b[j-1]);
                j--;                
            }
        }
    }
    cout<<"Check 2: "<<endl;
    while(i > 0){
        res.push_back(a[i-1]);
        i--;
    }
    while (j> 0)
    {
        res.push_back(b[j-1]);
        j--;
    }
    
    reverse(res.begin(), res.end());
    cout<<"Rrs: "<<res<<endl;

    
}

int main(){
    // print th eshortest common super sequence
    string a = "acbcf";
    string b = "abcdaf";

    int m = a.length();
    int n = b.length();

    printScs(a,b,m,n);

    return 0;
}