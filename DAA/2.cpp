#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(vector<vector<int>> &graph, vector<int> &colors, int start)
{
    queue<int> q;
    q.push(start);
    colors[start] = 1;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int neighbor : graph[curr])
        {
            if (colors[neighbor] == colors[curr])
                return false;

            if (colors[neighbor] == 0)
            {
                colors[neighbor] = -1 * colors[curr];
                q.push(neighbor);
            }
        }
    }
    cout << "Colors: ";
    for (int c : colors)
        cout << c << " ";
    cout << endl;
    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int N = graph.size();
    vector<int> colors(N, 0);

    for (int i = 0; i < N; ++i)
    {
        if (colors[i] == 0)
        {
            if (!bfs(graph, colors, i))
                return false;
        }
    }

    return true;
}

int main()
{
    int N;
    cout << "Enter the number of vertices: ";
    cin >> N;

    vector<vector<int>> graph(N, vector<int>(N, 0));

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cin >> graph[i][j];
    }

    if (isBipartite(graph))
        cout << "Yes Bipartite" << endl;
    else
        cout << "Not Bipartite" << endl;

    return 0;
}
