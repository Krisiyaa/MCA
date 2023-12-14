#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int>> &adjMat, int src, int v, bool visited[])
{
    visited[src] = true;

    for (int i = 0; i < v; i++)
    {
        if (adjMat[src][i] == 1 && !visited[i])
            DFS(adjMat, i, v, visited);
    }
}

bool ispath(vector<vector<int>> &adjMat, int src, int des, int v)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    DFS(adjMat, src, v, visited);

    return visited[des];
}

int main()
{
    int v;
    cout << "size: ";
    cin >> v;

    vector<vector<int>> adjMat(v, vector<int>(v, 0));

    cout << "adj mat\n";

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            cin >> adjMat[i][j];
    }
    int src, des;
    cin >> src >> des;

    if (ispath(adjMat, src, des, v))
    {
        cout << "Yes, Path Exists";
    }
    else
        cout << "No Such Path Exists";

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