#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

//iterative solution
long long make_change(vector<int> coins, int money)
{
    vector<long long> dp(money+1);
    
    fill(dp.begin(),dp.end(),0);
    
    dp[0]=1;
    
    for(int i=0; i<coins.size();i++)
        for(int j=coins[i]; j<money+1;j++)
            dp[j] += dp[j - coins[i]];
    
    return dp[money];
    
}

//recursive solution 
long long make_change(vector<int> coins, int money, vector<vector<long long>> &dp, int j=0) {
    if(money < 0)
        return 0;
    
    if(money == 0)
    {
        return 1;
    }
    
    if(dp[j][money-1] >= 0)
    {
        return dp[j][money-1];
    }
        
    long long count = 0;
    for(int i=j; i<coins.size();i++){
        count += make_change(coins, money - coins[i], dp, i);
    }
    
    dp[j][money-1] = count;
    
    return count;
}


int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> coins(m);
    
    vector<vector<long long>> dp(m,vector<long long>(n));
    
    for(int i=0;i<dp.size();i++)
        fill(dp[i].begin(),dp[i].end(),-1);
    
    for(int coins_i = 0;coins_i < m;coins_i++){
       cin >> coins[coins_i];
    }
    cout << make_change(coins, n, dp) << endl;
    
    return 0;
}
