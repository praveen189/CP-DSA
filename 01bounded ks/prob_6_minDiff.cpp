#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int minDiffFun(vector<int> &arr, int n, int sum)
{
    int t[n + 1][sum + 1];

    for (int j = 0; j < sum + 1; j++)
    {
        t[0][j] = false;
    }

    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = true;
    }

    // code
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                // lo ye na lo
                t[i][j] = ((t[i - 1][j - arr[i - 1]]) || t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    vector<int> vec;
    for (int j = 0; j < sum + 1; j++)
    {
        vec.push_back(t[n][j]);
    }

    int minVal = INT_MAX;

    for (int j = 0; j < (sum + 1) / 2; j++)
    {
        if (vec[j] == true)
        {
            if (minVal > vec[j])
            {
                minVal = (sum - 2 * j);
            }
        }
    }

    for (int j = 0; j < sum + 1; j++)
    {
        cout << vec[j] << " ";
    }
    cout << endl;

    return minVal;
}
int main()
{
    // min diff
    // s1 - s2c = min
    vector<int> arr = {5, 6, 6, 5, 7, 4, 7, 6};
    int n = arr.size();

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int minDiff = minDiffFun(arr, n, sum);
    cout << "Min Difference: " << minDiff << endl;

    return 0;
}