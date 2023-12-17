#include <bits/stdc++.h>
using namespace std;

bool bfs(int src, vector<vector<int>> &graph, vector<int> &color) {
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        src = q.front();
        q.pop();
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[src][i] == 1) {
                if (color[i] == -1) {
                    color[i] = 1 - color[src];
                    q.push(i);
                } else if (color[i] == color[src]) 
                    return false;
            }
        }
    }
    return true;
}

bool isGraphBipartite(vector<vector<int>> &edges) {
    int n = edges.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            color[i] = 1;
            if (!bfs(i, edges, color))
                return false;
        }
    }
    return true;
}

int main() {
    int N;
    cout << "Size :- ";
    cin >> N;

    vector<vector<int>> graph(N, vector<int>(N, 0));

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> graph[i][j];
        }
    }

    if (isGraphBipartite(graph)) {
        cout << "Yes Bipartite" << endl;
    } else {
        cout << "Not Bipartite" << endl;
    }

    return 0;
}



// 0 1 1 0 0
// 1 0 1 1 1
// 1 1 0 1 0
// 0 1 1 0 1
// 0 1 0 1 0