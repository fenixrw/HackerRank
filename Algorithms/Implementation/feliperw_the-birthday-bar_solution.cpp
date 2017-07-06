#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m, d;
    
    cin >> n;
    
    vector<int> bar(n);
    
    for(int i=0; i<n; i++)
    {
        cin >> bar[i];
    }
        
    cin >> d >> m;
    
    int totalWays = 0;
    
    for(int i=0; i<n; i++)
    {        
        int sum = 0;
        for(int j=0; (j+i)<n && j<m; j++)
        {
            sum+= bar[j+i];
            
            if(sum == d && (j+1) == m)
                totalWays++;
            else if(sum > d)
                break;
        }
    }
    
    cout << totalWays;
    
    return 0;
}
