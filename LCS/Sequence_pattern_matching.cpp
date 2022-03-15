#include<iostream>
#include<vector>

using namespace std;

void lcs(string a, string b, int m, int n){
    // approach 
   /* 1. find the lcs 
    and check if length of lcs() == min(a.length, b.length) 
    // bsc this will check that the any smaller str is a substring of other string or not 
    */
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

   // now we have length of lcs
   if(t[m][n] == m){
       cout<<"true:  "<<true<<endl;
   }
   else{
       cout<<"Flase:  "<<false<<endl;
   }
   
   
}
int main(){
    // return t: if you a string is subsequnce of b sting, else flase
    string a = "axy";
    string b = "adxcpy";

    int m = a.length();
    int n = b.length();

    lcs(a,b,m,n);

    return 0;
}