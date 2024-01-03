#include <bits/stdc++.h>
using namespace std;

bool bfs(int src, vector<vector<int>> &adj, vector<int> &vis,int n)
{
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        src = q.front();
        q.pop();
        for (int i = 0; i < n; ++i)
        {
            if (adj[src][i] == 1)
            {
                if (vis[i] == -1)
                {
                    vis[i] = 1 - vis[src];
                    q.push(i);
                }
                else if (vis[i] == vis[src])
                    return false;
            }
        }
    }
    return true;
}

bool check(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> vis(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == -1)
        {
            vis[i] = 1;
            if (!bfs(i, adj, vis,n))
                return false;
        }
    }
    return true;
}

int main()
{
    int N;
    cout << "Size :- ";
    cin >> N;

    vector<vector<int>> adj(N, vector<int>(N, 0));

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> adj[i][j];
        }
    }

    if (check(adj))
    {
        cout << "Yes Bipartite" << endl;
    }
    else
    {
        cout << "Not Bipartite" << endl;
    }

    return 0;
}

0 1 1 0 0
1 0 1 1 1
1 1 0 1 0
0 1 1 0 1
0 1 0 1 0


0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0