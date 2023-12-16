
#include <iostream>
#include <vector>

using namespace std;
void DFS(vector<vector<int>> &adjMat, int n, int src, vector<bool> &vis)
{
    vis[src] = true;
    cout<<src<<" ";
    for (int i = 0; i < n; i++)
    {
        if (adjMat[src][i] == 1 && !vis[i])
        {
            DFS(adjMat, n, i, vis);
        }
    }
}   

bool ischeck(vector<vector<int>> &adjMat, int n, int src, int des)
{
    vector<bool> vis(n, false);
    DFS(adjMat, n, src, vis);
    return vis[des];
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> adjMat(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> adjMat[i][j];
    }
    int src, des;
    cin >> src >> des;

    if (ischeck(adjMat, n, src, des))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}