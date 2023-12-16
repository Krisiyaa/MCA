#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
#include <algorithm>

#define INF INT_MAX

using namespace std;

int solve(vector<int> &wt,int i,int j){
    
    if(i+1 == j)
        return 0;
    
    int mn=INT_MAX;
    for(int k=i+1;k<j;k++){
        int sum=solve(wt,i,k)+solve(wt,k,j)+wt[i]*wt[j]*wt[k];
        mn=min(mn,sum);
    }

    return mn;
}

int main()
{
    vector<int> wt = {10, 30, 5, 60};
    int n = wt.size();
    // cout << n;

    cout<<"\n"<<solve(wt,0,n-1);

    return 0;
}

// 0 1 1 0 0
// 1 0 0 1 1
// 1 0 0 0 0
// 0 1 0 0 1
// 0 1 0 1 0

// 2 3 3 4 6
// 1 2 5 9 4