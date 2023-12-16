#include <iostream>
#include <vector>

using namespace std;

bool DFS(vector<vector<int>> &adjMat, int src, int n, vector<bool> &vis, vector<bool> &st)
{
    vis[src] = true;
    st[src] = true;

    for (int i = 0; i < n; i++)
    {
        if (adjMat[src][i] == 1)
        {
            if (!vis[i] && DFS(adjMat, i, n, vis, st))
                return true;
            else if (st[i])
                return true;
        }
    }

    st[src] = false;
    return false;
}

bool ischeck(vector<vector<int>> &adjMat, int n)
{
    vector<bool> vis(n, 0);
    vector<bool> st(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (DFS(adjMat, i, n, vis, st))
                return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Size :- ";
    cin >> n;

    vector<vector<int>> adjMat(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> adjMat[i][j];
    }

    if (ischeck(adjMat, n))
        cout << "YES \n";
    else
        cout << "NO \n";

    return 0;
}