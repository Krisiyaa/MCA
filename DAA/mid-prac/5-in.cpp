#include <iostream>
#include <vector>

using namespace std;

void sel(vector<int> &arr, int n)
{

    for (int i = 1; i < n; i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && key<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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