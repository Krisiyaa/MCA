#include <bits/stdc++.h>

#define INF INT_MAX

using namespace std;

bool DFS(vector<vector<int>>& adj,int n,int src,vector<bool>&vis,vector<bool>&st)
{
    vis[src]=true;
    st[src]=true;

    for(int i=0;i<n;i++){
        if(adj[src][i]){
            if(!vis[i] && DFS(adj,n,i,vis,st))
                return true;
            else if(st[i])
                return true;
        }
    }
    st[src]=false;
    return false;
}

bool check(vector<vector<int>>& adj,int n)
{
    vector<bool>vis(n,false);
    vector<bool>st(n,false);

    for(int i=0;i<n;i++){
        if(!vis[i] && DFS(adj,n,i,vis,st))
            return true;
    }
    return false;
}

int main()
{

    int n;
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];
    }

    if (check(adj, n))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}

// 0 1 1 0 0
// 1 0 1 1 1
// 1 1 0 1 0
// 0 1 1 0 1
// 0 1 0 1 0

// 0 1 1 0 0
// 0 0 0 1 1
// 0 1 0 1 0
// 0 0 0 0 1
// 0 0 0 0 0

// 2 3 3 4 6
// 1 2 5 9 4