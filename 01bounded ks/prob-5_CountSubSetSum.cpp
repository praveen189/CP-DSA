#include <iostream>
#include <vector>

using namespace std;

int countSubSetSum(vector<int> &arr, int n, int sum)
{
    int t[n + 1][sum + 1];

    // initialization
    for (int j = 0; j < sum + 1; j++)
    {
        t[0][j] = 0;
    }

    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = 1;
    }

    // code.
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i-1] <= j)
            {
                // 2 case lo, ye na lo
                t[i][j] = ((t[i - 1][j - arr[i - 1]]) + (t[i - 1][j]));
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    for(int  i =0; i<n+1; i++){
        for(int j = 0;j<sum+1; j++){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    return t[n][sum];
}

int main()
{
    // prob-5: count subset summ return: count
    vector<int> arr = {4, 3, 1, 7, 8, 10};
    int sum = 11;

    int n = arr.size();

    int ans = countSubSetSum(arr, n, sum);
    cout << "No of sub set with given sum: " << ans;

    return 0;
}