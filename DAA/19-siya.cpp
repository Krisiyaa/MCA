#include <iostream>
#include <cstdlib>
#include <limits.h>

#define SZ 10

using namespace std;

int P[] = {10, 30, 5, 60};

int MCM(int i, int j)
{
    if (i + 1 == j)
        return 0;

    int mn = INT_MAX;

    for (int k = i + 1; k < j; k++)
    {
        int sum = MCM(i, k) + MCM(k, j) + P[i] * P[k] * P[j];
        mn = min(mn, sum);
    }

    return mn;
}

int main()
{
    int size = sizeof(P) / sizeof(P[0]);

    cout << "Minimum number of mutiplications is " << MCM(0, size - 1);

    return 0;
}

/*OUTPUT DESCRIPTION*/
/*
              P = {10, 20, 30, 40, 30},
              dimensions of matrix [1] = 10X20,
              dimensions of matrix [2] = 20X30,
              dimensions of matrix [3] = 30X40,
              dimensions of matrix [4] = 40X30


         This is how mat[][] matrix will look like

                0 6000 18000 30000
                0 0    24000 48000
                0 0    0     36000
                0 0    0     0

                                     ,where mat[1][size-1]=30000 is the answer.
*/