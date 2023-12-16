#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void knapSack(int K, int wt[], int P[], int n, vector<int> &selectedItems)
{
    int i, w;
    int DP[n + 1][K + 1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= K; w++)
        {
            if (i == 0 || w == 0)
                DP[i][w] = 0;
            else if (wt[i - 1] <= w)
                DP[i][w] = max(P[i - 1] + DP[i - 1][w - wt[i - 1]], DP[i - 1][w]);
            else
                DP[i][w] = DP[i - 1][w];
        }
    }

    // Backtrack to find the selected items
    i = n;
    w = K;
    while (i > 0 && w > 0)
    {
        if (DP[i][w] != DP[i - 1][w])
        {
            selectedItems.push_back(i - 1);
            w -= wt[i - 1];
        }
        i--;
    }
}

int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int wt[n], P[n];

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++)
        cin >> P[i];

    int K;
    cout << "Enter the knapsack capacity: ";
    cin >> K;

    vector<int> selectedItems;
    knapSack(K, wt, P, n, selectedItems);

    cout << "Output:\n";

    int sum=0;
    for (int i = 0; i < selectedItems.size(); i++)
        sum += P[selectedItems[i]];

    cout << "Maximum Value = " << sum << endl;
    cout << "Weights selected: ";
    for (int i = selectedItems.size() - 1; i >= 0; i--)
        cout << wt[selectedItems[i]] << " ";
    cout << endl;

    cout << "Values of selected weights: ";
    for (int i = selectedItems.size() - 1; i >= 0; i--)
        cout << P[selectedItems[i]] << " ";
    cout << endl;

    return 0;
}

// 2 3 3 4 6
// 1 2 5 9 4