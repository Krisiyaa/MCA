#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int>> &adjMat, int src, int n, vector<bool> &vis)
{
    vis[src] = true;
    cout << src << " ";

    for (int i = 0; i < n; i++)
    {
        if (adjMat[src][i] == 1 && !vis[i])
            DFS(adjMat, i, n, vis);
    }
}

bool ischeck(vector<vector<int>> &adjMat, int n, int src, int des)
{
    vector<bool> vis(n, false);

    DFS(adjMat, src, n, vis);

    return vis[des];
}

int main()
{
    int n;
    cout << "Size";
    cin >> n;
    vector<vector<int>> adjMat(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adjMat[i][j];
        }
    }
    int src, des;
    cout << "Enter src and des";
    cin >> src >> des;

    if (ischeck(adjMat, n, src, des))
        cout << "YES";
    else
        cout << "No";

    return 0;
}

// 0 1 1 0 0
// 1 0 1 1 1
// 1 1 0 1 0
// 0 1 1 0 1
// 0 1 0 1 0

// 0 1 1 0 0
// 1 0 0 1 1
// 1 0 0 0 0
// 0 1 0 0 1
// 0 1 0 1 0
