#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <thread>
using namespace std;

long long walkCities(unsigned long long city, vector<vector<unsigned long long>> &roads, vector<bool> &cities)
{
    unsigned long long r = 0;
    queue<unsigned long long> nextToVisit;
    cities[city] = true;
    nextToVisit.push(city);
    
    while(!nextToVisit.empty())  
    {
        unsigned long long c = nextToVisit.front();
        nextToVisit.pop();
        for(unsigned long long j=0;j<roads[c].size();j++)
        //for(unsigned long long j=0;j<roads[city].size();j++)
        {
            unsigned long long i = roads[c][j];
            //unsigned long long i = roads[city][j];
            if(!cities[i])
            {
                cities[i] = true;
                nextToVisit.push(i);
                r++;
                //r+= walkCities(i, roads, cities) + 1;
            }
        }
    }
    
    return r;
    
}

void threadBFS(vector<vector<unsigned long long>> roads, vector<bool> cities,unsigned long long clib, unsigned long long croad, unsigned long long *out)
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
    *out = clib*libCount + croad*roadCount;
    
    //cout << clib*libCount + croad*roadCount << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unsigned long long q,n,m,clib,croad;
    cin >> q;
    
    thread* t[10];
    unsigned long long res[10];
    
    for(unsigned long long i=0; i<q; i++)
    {
        cin >> n;
        cin >> m;
        cin >> clib;
        cin >> croad;
        
        t[i] = NULL;
        
        vector<vector<unsigned long long>> roads(n);
        vector<bool> cities(n);
        
        for(unsigned long long j=0;j<n;j++)
        {
            cities[j]=false;
        }
        
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
            //cout << clib*n << endl;
            res[i] = clib*n;
        }
        else
        {
            /*unsigned long long libCount = 0;
            unsigned long long roadCount = 0;
            //unsigned long long index = 0;
            
            //while(checkCities(cities, index))
            for(unsigned long long index=0;index<cities.size();index++)
            {
                if(!cities[index])
                {
                    libCount++;
                    roadCount += walkCities(index, roads, cities);
                }
            }
            
            cout << clib*libCount + croad*roadCount << endl;*/
            t[i] = new thread(threadBFS,roads,cities,clib,croad,&(res[i]));
        }
        
    }
    
    
    for(unsigned long long i=0; i<q; i++)
    {
        if(t[i] != NULL)
        {
            t[i]->join();
        }
        
        cout << res[i] << endl;
    }
    
    return 0;
}
