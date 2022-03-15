#include <iostream>
#include <vector>

using namespace std;

bool subSetSum(vector<int> &arr, int n, int sum){
    int t[n + 1][sum + 1];
    // initialization
    for(int j = 0; j<sum+1; j++){
        t[0][j] = false;
    }
    for(int i = 0; i<n+1; i++){
        t[i][0] = true;
    }
    // code
    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < sum + 1; j++){
            if (arr[i - 1] <= j){
                // two case.
                t[i][j] = ((t[i - 1][j - arr[i - 1]]) || (t[i - 1][j]));
            }
            else if (arr[i - 1] > j){
                t[i][j] = t[i - 1][j];
            }
        }
    } 
    return t[n][sum];
}

int main()
{
    // prob-3 subsetsum T/F.
    vector<int> arr = {1, 5, 7, 8, 10};
    int sum = 11;

    int n = arr.size();

    cout << subSetSum(arr, n, sum);

    return 0;
}
// O/P: 1- true 0- false