#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main(){
    // find the max sum of continuous in array
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = arr.size();

    //**** approach 
    /*1. find current sum 
    2. and if currt sum > sumTill, update sumTill now = currt SUBVERSION_MASK
    3. if -ve cuurt then make it 0
    */
   int currSum = 0, maxTillNow = INT_MIN;
   for (int  i = 0; i < n; i++)
   {
       currSum += arr[i];

       maxTillNow = max(maxTillNow, currSum);

       if(currSum < 0){
           currSum = 0;
       }
   }

   cout<<"Max sum : "<<maxTillNow<<endl;

   return 0;

   
}