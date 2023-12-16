#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapSack(int K, const vector<int> &wt, const vector<int> &val, int n, vector<int> &selectedItems)
{
    vector<vector<int>> DP(n + 1, vector<int>(K + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (wt[i - 1] > j)
                DP[i][j] = DP[i - 1][j];
            else
                DP[i][j] = max(val[i - 1] + DP[i - 1][j - wt[i - 1]], DP[i - 1][j]);
        }
    }

    int i = n;
    int j = K;
    while (i > 0 && j > 0)
    {
        if (DP[i][j] != DP[i - 1][j])
        {
            selectedItems.push_back(i - 1);
            j -= wt[i - 1];
        }
        i--;
    }

    return DP[n][K];
}

int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> wt(n), val(n);

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++)
        cin >> val[i];

    int K;
    cout << "Enter the knapsack capacity: ";
    cin >> K;

    vector<int> selectedItems;
    int maxValue = knapSack(K, wt, val, n, selectedItems);

    cout << "Maximum Value: " << maxValue << endl;
    cout << "Weights selected: ";

    for (int i = selectedItems.size() - 1; i >= 0; i--)
        cout << wt[selectedItems[i]] << " ";
    cout << endl;

    cout << "Values of selected weights: ";

    for (int i = selectedItems.size() - 1; i >= 0; i--)
        cout << val[selectedItems[i]] << " ";
    cout << endl;

    return 0;
}

// 2 3 3 4 6
// 1 2 5 9 4