#include <iostream>
#include <limits.h>
#include <iomanip>
#include <vector>

#define INF INT_MAX
#define A 5

using namespace std;

void output(const vector<vector<int>> &length)
{
    for (int x = 0; x < A; x++)
    {
        for (int y = 0; y < A; y++)
        {
            if (length[x][y] == INF)
                cout << setw(12) << "INF";
            else
                cout << setw(12) << length[x][y];
        }
        cout << endl;
    }
}

void FloydWarshall(const vector<vector<int>> &graph)
{
    vector<vector<int>> length = graph;

    for (int z = 0; z < A; z++)
    {
        for (int x = 0; x < A; x++)
        {
            for (int y = 0; y < A; y++)
            {
                if (length[x][z] != INF &&
                    length[z][y] != INF &&
                    length[x][z] + length[z][y] < length[x][y])
                    length[x][y] = length[x][z] + length[z][y];
            }
        }
    }
    output(length);
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