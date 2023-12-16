#include <iostream>
#include <limits.h>
#include <iomanip>
#include <vector>

#define INF INT_MAX
#define A 5

using namespace std;

void output(vector<vector<int>> &mat)
{
    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < A; j++)
        {
            if (mat[i][j] == INF)
                cout << setw(12) << "INF";
            else
                cout << setw(12) << mat[i][j];
        }
        cout << endl;
    }
}

void FloydWarshall(vector<vector<int>> &graph)
{
    vector<vector<int>> mat = graph;

    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < A; j++)
        {
            for (int k = 0; k < A; k++)
            {
                if (mat[j][i] != INF && mat[i][k] != INF && mat[j][i] + mat[i][k] < mat[j][k])

                    mat[j][k] = mat[j][i] + mat[i][k];
            }
        }
    }
    output(mat);
}

int main()
{
    vector<vector<int>> graph = {{0, 10, 5, 5, INF},
                                 {INF, 0, 5, 5, 5},
                                 {INF, INF, 0, INF, 10},
                                 {INF, INF, INF, 0, 20},
                                 {INF, INF, INF, 5, 0}};

    FloydWarshall(graph);
    return 0;
}

// Input:
// 5
// 0 10 5 5 INF
// INF 0 5 5 5
// INF INF 0 INF 10
// INF INF INF 0 20
// INF INF INF 5 0

// Output:
// Shortest Distance Matrix:
// 0 10 15 5 15
// INF0555
// INF INF 0 15 10
// INF INF INF 0 20
// INF INF INF 5 0