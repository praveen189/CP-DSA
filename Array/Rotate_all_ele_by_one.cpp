#include <iostream>

using namespace std;

void print(int arr[], int n, int r)
{
    cout << "Rotation: " << r+1<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void roateByOne(int arr[], int n)
{

    int last = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }

    // insert the last element to first
    arr[0] = last;
}
int main()
{
    // roate array by one index
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
     print(arr, n);

    int noOfRoatation = 3;
    for (int i = 0; i < noOfRoatation; i++)
    {
        roateByOne(arr, n);
        print(arr, n, i);
    }

    // print(arr, n);
    return 0;
}