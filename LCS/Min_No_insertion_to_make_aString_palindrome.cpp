#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void lps(string a, string b, int m, int n)
{
    int t[m + 1][n + 1];
    for (int j = 0; j < n + 1; j++)
    {
        t[0][j] = 0;
    }
    for (int i = 0; i < m + 1; i++)
    {
        t[i][0] = 0;
    }

    // choice diag
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    // now have length of lps
    int noOfDeletion = (m - t[m][n]);
    int noOfInsertion = (m - t[m][n]);

    // as # on insertion will be same as of deletion as to find the lps (we delete those letter whose pair was not their in string so, for insertion same we will add only those letter whose pair was not present in b )
    cout<<"noOfDeletion: "<<noOfDeletion<<endl;
    cout<<"No of insertion: "<<noOfInsertion<<endl;

    
}

int main()
{
    // min # of insertion to be made to makea string palindrome
    string a = "aebcbda";

    // *** approach
    /*1. create a reverse of a string
    2. now find lcs or lcs(as we will find the lps between them)
    3. now just compare the length of a and lps as those letter are not on lps (diff index will not in the lps)
    4. find the
    */

    string b = a;
    reverse(a.begin(), a.end());

    lps(a, b, a.length(), b.length());

    return 0;
}