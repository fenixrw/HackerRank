#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int s,n,m;
    cin >> s >> n >> m;
    vector<vector<long>> prices(n,vector<long>(m));
    
    for(int i=0; i<n; i++){
        long c;
        cin >> c;
        fill(prices[i].begin(),prices[i].end(), c);
    }
    
    long result = -1;
    
    for(int j=0; j<m; j++){
        long c;
        cin >> c;
        for(int i=0; i<n; i++){
            prices[i][j]+=c;
            if(prices[i][j] <= s && prices[i][j]>result)
            {
                result = prices[i][j];
                if(prices[i][j] == s)
                {
                    cout << result;
                    return 0;
                }
            }
        }
    }
    
    cout << result;
    
    return 0;
}
