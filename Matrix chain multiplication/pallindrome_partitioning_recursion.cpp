#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPalindromic(string s, int i ,int j){
    // bool res = true;
    while( i<= j){
        if(s[i] != s[j]){
        return false;
        }
        i++;
        j--;

       
    }
    return true;
}

int solve(string s, int i, int j){
    // recursive 
    // bc 
    if(i >= j){
        // 1. " "
        // 2. "a"
        // will have o partion as a none and single letter can't have partition 
        return 0;
    }

    // for the palindromic strin min # of partition is 0 
    if(isPalindromic(s,i,j) == true){
        return 0;
    }

    // move k to (i --- j)

    int mn = INT_MAX;
    for(int k = i; k<=j-1; k++){
        int temp = ( solve(s,i,k) + solve(s,k+1, j) + 1 );
        // last 1 is for the two partition string from k will be have one way for partion as combine

        mn = min(mn, temp);
    }

    return mn;
}

int main(){
    // find min # of partition for palindrome string 
    // string s = "ababbbabbababa";
    string s = "nitin";

    // max can be n-1 (divide it each letter)
    int n = s.length();

    // steps: 
    /*1. find i and j
    2. find bc
    3. move k to (i --- j)
    4. cal. ans form temp ans 
    */

   int i = 0; 
   int j = n-1;

   cout<<"Min # of partition: "<<solve(s, i, j);

   return 0;

}