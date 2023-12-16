// #include <iostream>
// #include <vector>

// using namespace std;

// void DFS(vector<vector<int>> &adjMat, int s, bool visited[], int v)
// {
//     visited[s] = true;
//     cout<<s<<" ";

//     for (int u = 0; u < v; ++u)
//     {
//         if (adjMat[s][u] == 1 && !visited[u])
//             DFS(adjMat, u, visited, v);
//     }
// }

// bool isPathExists(vector<vector<int>> &adjMat, int v, int src, int des)
// {
//     bool visited[v];
//     for (int i = 0; i < v; i++)
//         visited[i] = false;

//     DFS(adjMat, src, visited, v);

//     return visited[des];
// }

// int main()
// {
//     int v;
//     cout << "Enter the number of vertices: ";
//     cin >> v;

//     vector<vector<int>> adjMat(v, vector<int>(v, 0));

//     cout << "Enter the adjacency matrix:" << endl;
//     for (int i = 0; i < v; i++)
//     {
//         for (int j = 0; j < v; j++)
//             cin >> adjMat[i][j];
//     }

//     int src, des;
//     cout << "Enter the source and destination vertices: ";
//     cin >> src >> des;

//     if (isPathExists(adjMat, v, src, des))
//         cout << "Yes, Path Exists" << endl;
//     else
//         cout << "No Such Path Exists" << endl;

//     return 0;
// }

//   0 1 2 3 4
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

// #include <iostream>
// #include <vector>

// using namespace std;

// void DFS(vector<vector<int>> &adjMat, int src, int n, vector<bool> &vis)
// {
//     vis[src] = true;
//     cout << src;

//     for (int i = 0; i < n; i++)
//     {
//         if (adjMat[src][i] == 1 && !vis[i])
//             DFS(adjMat, i, n, vis);
//     }
// }

// bool ischeck(vector<vector<int>> &adjMat, int n, int src, int des)
// {
//     vector<bool> vis(n, false);

//     DFS(adjMat, src, n, vis);

//     return vis[des];
// }

// int main()
// {
//     int n;
//     cout << "Size: ";
//     cin >> n;
//     vector<vector<int>> adjMat(n, vector<int>(n, 0));

//     cout << "Enter adjacency matrix:\n";
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> adjMat[i][j];
//         }
//     }

//     int src, des;
//     cout << "Enter src and des: ";
//     cin >> src >> des;

//     if (ischeck(adjMat, n, src, des))
//         cout << "YES\n";
//     else
//         cout << "NO\n";

//     return 0;
// }

#include <iostream>
#include <vector>

using namespace std;
bool DFS(vector<vector<int>> &adjMat, int n, int src, vector<bool> &vis, vector<bool> &st)
{
    vis[src] = true;
    st[src] = true;

    for (int i = 0; i < n; i++)
    {
        if (adjMat[src][i] == 1)
        {
            if (!vis[i] && DFS(adjMat, n, i, vis, st))
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
    vector<bool> vis(n, false);
    vector<bool> st(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && DFS(adjMat, n, i, vis, st))
                return true;
    }
    return false;
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

    if (ischeck(adjMat, n))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}