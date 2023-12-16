#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
    int index;
    double ratio; // value-to-weight ratio
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

void fractionalKnapsack(int n, vector<int>& weights, vector<int>& values, int capacity) {
    vector<Item> items(n);

    // Calculate value-to-weight ratio for each item
    for (int i = 0; i < n; ++i) {
        items[i].weight = weights[i];
        items[i].value = values[i];
        items[i].index = i + 1; // 1-based indexing
        items[i].ratio = static_cast<double>(values[i]) / weights[i];
    }

    // Sort items based on value-to-weight ratio in descending order
    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0;
    vector<double> fractions(n, 0.0);

    for (int i = 0; i < n; ++i) {
        if (capacity <= 0)
            break;

        int currentWeight = items[i].weight;
        int currentValue = items[i].value;

        if (capacity >= currentWeight) {
            fractions[items[i].index - 1] = 1.0;
            capacity -= currentWeight;
            maxValue += currentValue;
        } else {
            fractions[items[i].index - 1] = static_cast<double>(capacity) / currentWeight;
            maxValue += fractions[items[i].index - 1] * currentValue;
            capacity = 0;
        }
    }

    // Output the result
    cout << "Maximum value: " << maxValue << endl;
    cout << "item-weight" << endl;

    for (int i = 0; i < n; ++i) {
        cout << items[i].index << "-" << fractions[i] << endl;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> weights(n);
    vector<int> values(n);

    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    int capacity;
    cin >> capacity;

    fractionalKnapsack(n, weights, values, capacity);

    return 0;
}
