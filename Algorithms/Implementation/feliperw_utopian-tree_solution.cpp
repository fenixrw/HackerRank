#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long h=1;
    int maxCycles = 0;
    int n;
    cin >> n;
    vector<int> dp(61);
    
    dp[0]=1;
    
    for(int i=0;i<n;i++)
    {
        int cycles;
        cin >> cycles;
        
        if(cycles <= maxCycles)
        {
            cout << dp[cycles] << endl;
        }
        else
        {
            for(int j=maxCycles;j<cycles;j++,maxCycles++)
            {
                h+=((j%2==0)?h:1);
                dp[j+1] = h;
            }
            
            cout << h << endl;
        }
        
    }
    
    
    return 0;
}
