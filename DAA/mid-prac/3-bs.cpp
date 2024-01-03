#include <iostream>
#include <vector>

using namespace std;

int bsr(vector<int> &arr, int n, int key)
{
    int low = 0;
    int high = n - 1;
    int r = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            r = mid;
            low = mid + 1;
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return r;
}

int bsl(vector<int> &arr, int n, int key)
{
    int low = 0;
    int high = n - 1;
    int l = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            l = mid;
            high = mid - 1;
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return l;
}

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cin >> key;

    int l = bsl(arr, n, key);
    int r = bsr(arr, n, key);
    cout << r - l + 1;

    return 0;
}