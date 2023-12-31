#include <iostream>
#include <cstdlib>
#include <limits.h>

#define SZ 10

using namespace std;

int table[SZ][SZ];

int P[] = {10, 30, 5, 60};

int MCM(int i, int j)
{
    if (i == j)
        return 0;

    int min = INT_MAX;

    for (int k = i; k < j; k++)
    {
        if (table[i][k] == 0)
            table[i][k] = MCM(i, k);

        if (table[k + 1][j] == 0)
            table[k + 1][j] = MCM(k + 1, j);

        int sum = table[i][k] + table[k + 1][j] + P[i - 1] * P[j] * P[k];
        if (sum < min)
            min = sum;
    }

    table[i][j] = min;
    return min;
}

int main()
{
    int size = sizeof(P) / sizeof(P[0]);

    cout << "Minimum number of mutiplications is " << MCM(1, size - 1);

    return 0;
}

/*OUTPUT DESCRIPTION*/
/*
              P = {10, 20, 30, 40, 30},
              dimensions of matrix [1] = 10X20,
              dimensions of matrix [2] = 20X30,
              dimensions of matrix [3] = 30X40,
              dimensions of matrix [4] = 40X30


         This is how table[][] matrix will look like

                0 6000 18000 30000
                0 0    24000 48000
                0 0    0     36000
                0 0    0     0

                                     ,where table[1][size-1]=30000 is the answer.
*/
