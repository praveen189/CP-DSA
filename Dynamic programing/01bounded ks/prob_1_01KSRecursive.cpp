#include <iostream>
#include <vector>

using namespace std;

int ksFun(vector<int> &wt, vector<int> &val, int n, int w)
{
    // bc.
    if (n == 0 || w == 0)
    {
        return 0; // no profit
    }

    // choice diagram
    // two choice - 1. either we take that value   2. do not takes that value
    if (wt[n - 1] <= w)
    {
        // 2 choice lo , na lo
        return max((val[n - 1] + ksFun(wt, val, n - 1, w - wt[n - 1])), ksFun(wt, val, n - 1, w));
    }
    else
    {
        return ksFun(wt, val, n - 1, w);
    }

    return 0;
}
int main()
{
    // prob-1 01 ks recursive
    // vector<int> wt = {1, 2, 3, 4, 5};
    vector<int> wt = {10, 20, 30};
    vector<int> val = {60, 100, 120};
    int w = 50;; // capacity of ks in kg

    int n = wt.size();
    int res = ksFun(wt, val, n, w);
    cout << "Max Profit: " << res << endl;

    return 0;
}
// O/P: Max Profit: 220