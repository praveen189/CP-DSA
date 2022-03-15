#include<iostream>
#include<vector>

using namespace std;
int NoOfWays(vector<int> &coin, int n ,int sum){
    // 
    int t[n+1][sum+1];
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<sum+1; j++){
            if(i == 0){
                t[i][j] = 0; 
            }
            if(j == 0){
                t[i][j] = 1;
            }
        }
    }

    //code
    for(int i = 1; i<n+1; i++){
        for(int j = 0; j<sum+1; j++){
            if(coin[i-1] <= j){
                // two case lo ye na lo
                t[i][j] = ( t[i][j-coin[i-1]]  + (t[i-1][j] ));
            }
            else{
                t[i][j] = (t[i-1][j] );
            }
        }
    }

    return t[n][sum];
}

int main(){
    // coin change problem 
    // no of way the sum canbe completed 
    vector<int> coin = {1,2,3};
    int sum = 5;

    // as we can take multiples 1 rupee coin so it is unbounded ks
    // sub set sum

    int n = coin.size();

    cout<<"No of ways sum can be made: "<<NoOfWays(coin, n, sum);

    return 0;
}