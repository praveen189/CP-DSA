#include <iostream>

using namespace std;

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1; // if not found.
}
int main()
{
    // linar search
    int arr[] = {3, 2, 5, 7, 91, 1};
    int key = 6;

    // o/p: index if found ohterwise -1;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "index of key: " << key << "is: " << linearSearch(arr, n, key);

    return 0;
}