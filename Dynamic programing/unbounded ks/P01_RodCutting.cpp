#include<iostream>
#include<vector>

using namespace std;

int MaxProfit(vector<int> &len,vector<int> &profit, int n, int length){
    int t[n+1][length+1];

    //initialization
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<length+1; j++){
            if(i == 0 || j == 0){
                t[i][j] = 0; // no profit
            }
        }
    }

    // code
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<length+1; j++){
            if(len[i-1] <= j){
                // lo ye na lo
                t[i][j] = max( (profit[i-1] + t[i][j-len[i-1]]) , (t[i-1][j]) ); 
            }
            else{
                t[i][j] = (t[i-1][j]);
            }
        }
    }

    return t[n][length];
}
int main(){
    // rod cutting  find max profit
    vector<int> len = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> profit = { 1, 5, 8, 9, 10, 17, 17, 20};
    int length = 4;
    //

    int n = len.size();

    int res = MaxProfit(len, profit, n, length);
    cout<<"Max profit: "<<res;
    return 0;
}