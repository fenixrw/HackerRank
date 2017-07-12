#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

unsigned long long walkCities(unsigned long long city, vector<vector<unsigned long long>> &roads, vector<bool> &cities)
{
    unsigned long long r = 0;
    cities[city] = true;
    
        for(unsigned long long j=0;j<roads[city].size();j++)
        {
            unsigned long long i = roads[city][j];
            if(!cities[i])
            {
                r+= walkCities(i, roads, cities) + 1;
            }
        }
    
    return r;
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unsigned long long q,n,m,clib,croad;
    cin >> q;
    
    for(unsigned long long i=0; i<q; i++)
    {
        cin >> n;
        cin >> m;
        cin >> clib;
        cin >> croad;
        
        vector<vector<unsigned long long>> roads(n);
        vector<bool> cities(n);
                
        for(unsigned long long j=0;j<m;j++)
        {
            unsigned long long a,b;
            cin >> a;
            cin >> b;
            roads[a-1].push_back(b-1);
            roads[b-1].push_back(a-1);;
        }
        
        if(clib < croad)
        {
            cout << clib*n << endl;
        }
        else
        {
            unsigned long long libCount = 0;
            unsigned long long roadCount = 0;
            
            for(unsigned long long index=0;index<cities.size();index++)
            {
                if(!cities[index])
                {
                    libCount++;
                    roadCount += walkCities(index, roads, cities);
                }
            }
            
            cout << clib*libCount + croad*roadCount << endl;
        }
        
    }
    
    return 0;
}
