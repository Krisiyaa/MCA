#include <bits/stdc++.h>
using namespace std;

// Function to compute maximum profit obtainable
double fractionalKnapsackProblem(vector<pair<double, pair<double, double>>>& arr, int nItems, int capacity) {
    // Sort the items based on the ratio of value to weight in non-decreasing order
    sort(arr.begin(), arr.end());

    double totalWeight = 0.0;  // Current total weight added to the knapsack
    double totalValue = 0.0;   // Current total value obtained from the knapsack

    // Items with greater value-to-weight ratio are selected first
    for (int i = (nItems - 1); i >= 0; i--) {
        // If adding the weight of the current item doesn't exceed the knapsack capacity, select it
        if ((totalWeight + arr[i].second.second) <= capacity) {
            totalWeight += arr[i].second.second;
            totalValue += arr[i].second.first;
        } else {
            // If exceeding the knapsack capacity, break the item into fractional parts
            double remainingFraction = (capacity - totalWeight) / arr[i].second.second;
            totalValue += arr[i].second.first * remainingFraction;
            break;
        }
    }

    return totalValue;
}

int main() {
    int nItems;
    cout << "Enter the number of items: ";
    cin >> nItems;

    vector<double> weights(nItems);
    vector<double> values(nItems);

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < nItems; ++i) {
        cin >> weights[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < nItems; ++i) {
        cin >> values[i];
    }

    int capacity;
    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> capacity;

    vector<pair<double, pair<double, double>>> items;
    for (int i = 0; i < nItems; ++i) {
        items.push_back(make_pair(values[i] / weights[i], make_pair(values[i], weights[i])));
    }

    double maxValue = fractionalKnapsackProblem(items, nItems, capacity);

    cout << fixed << setprecision(2); // Set precision for decimal places
    cout << "Maximum value: " << maxValue << endl;
    cout << "item-weight" << endl;

    // Output the selected items and their fractions
    for (int i = 0; i < nItems; ++i) {
        double fraction = min(1.0, weights[i] / items[i].second.second);
        cout << i + 1 << "-" << fraction << endl;
    }

    return 0;
}



// 6 10 3 5 1 3
// 6 2 1 8 3 5