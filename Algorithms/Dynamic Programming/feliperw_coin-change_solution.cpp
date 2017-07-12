#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long coinChange(vector<int> &c,  int n, vector<vector<long long>> &dp, int i=0)
{
    if(dp[i][n-1]>=0)
    {
        return dp[i][n-1];
    }
    
    if(n - c[i] == 0)
    {
        return 1;
    }
    else if(n - c[i] < 0)
    {
        return 0;
    }
    unsigned long long count = 0;
    for(int j=i;j<c.size();j++)
    {
        count+= coinChange(c,n - c[i],dp,j);
    }
    
    dp[i][n-1] = count;
    
    return count;
}


unsigned long long coinChange(vector<int> &c,  int n)
{
    vector<vector<long long>> dp(c.size(),vector<long long>(n));
    
    for(int i=0;i<c.size();i++)
        fill(dp[i].begin(),dp[i].end(),-1);
    
    unsigned long long count = 0;
    
    for(int i=0;i<c.size();i++)
        count +=coinChange(c,n,dp,i);
    
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,m;
    cin >> n >> m;
    vector<int> c(m);
    
    for(int i=0;i<m;i++)
        cin >> c[i];
    
    cout << coinChange(c,n) << endl;
    
    return 0;
}
