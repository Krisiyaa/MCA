#include <iostream>
#include <vector>

using namespace std;

void sel(vector<int> &arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        int mn = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[mn] > arr[j])
                mn = j;
        }
        swap(arr[mn], arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sel(arr, n);

    return 0;
}