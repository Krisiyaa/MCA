#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the most efficient way to multiply a sequence of matrices
int matrixChainMultiplication(vector<pair<int, int>>& dimensions) {
    int n = dimensions.size();
    
    // Create a 2D DP array to store the minimum number of operations
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Fill the DP array using bottom-up approach
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i - 1].first * dimensions[k].second * dimensions[j].second;
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n - 1];
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    vector<pair<int, int>> dimensions(n);

    // Input matrix dimensions
    for (int i = 0; i < n; i++) {
        cout << "Enter dimensions of matrix " << i + 1 << " (a b): ";
        cin >> dimensions[i].first >> dimensions[i].second;
    }

    // Calculate the minimum number of operations
    int result = matrixChainMultiplication(dimensions);

    // Output the result
    cout << "Minimum number of operations: " << result << endl;

    return 0;
}
