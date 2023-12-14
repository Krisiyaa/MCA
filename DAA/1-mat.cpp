#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int>> &adjMat, int s, bool visited[], int v)
{
    visited[s] = true;
    cout<<s<<" ";

    for (int u = 0; u < v; ++u)
    {
        if (adjMat[s][u] == 1 && !visited[u])
            DFS(adjMat, u, visited, v);
    }
}

bool isPathExists(vector<vector<int>> &adjMat, int v, int src, int des)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;

    DFS(adjMat, src, visited, v);

    return visited[des];
}

int main()
{
    int v; 
    cout << "Enter the number of vertices: ";
    cin >> v;

    vector<vector<int>> adjMat(v, vector<int>(v, 0));

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            cin >> adjMat[i][j];
    }

    int src, des;
    cout << "Enter the source and destination vertices: ";
    cin >> src >> des;

    if (isPathExists(adjMat, v, src, des))
        cout << "Yes, Path Exists" << endl;
    else
        cout << "No Such Path Exists" << endl;

    return 0;
}

 //  0 1 2 3 4
// 0 0 1 1 0 0
// 1 1 0 1 1 1
// 2 1 1 0 1 0
// 3 0 1 1 0 1
// 4 0 1 0 1 0


// 0 1 1 0 0
// 1 0 0 1 1
// 1 0 0 0 0
// 0 1 0 0 1
// 0 1 0 1 0    1->5

// 1 0 2 3 4

