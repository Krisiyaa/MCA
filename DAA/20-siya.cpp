#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool hasMajorityElement(const vector<int> &arr, int &mx)
{
    int n = arr.size();
    map<int, int> mp;

    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    int ct = 0;
    for (const auto &entry : mp)
    {
        if (entry.second > ct)
        {
            ct = entry.second;
            mx = entry.first;
        }
    }
    return ct > n / 2;
}

int findMedian(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    if (n % 2 == 0)
        return (arr[n / 2 - 1] + arr[n / 2]) / 2;
    else
        return arr[n / 2];
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array separated by space: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int mx;
    if (hasMajorityElement(arr, mx))
        cout << "Yes, Majority Element: " << mx << endl;
    else
        cout << "No majority element found." << endl;

    int median = findMedian(arr);
    cout << "Median: " << median << endl;

    return 0;
}

// 9
// 4 4 2 3 2 2 3 2 2
