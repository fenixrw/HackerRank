#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> value;
    
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        if(value.find(a[i])==value.end())
        {
            value[a[i]]=0;
        }
        value[a[i]]++;            
    }
    
    int maxSet = value.begin()->second;
    
    for(map<int, int>::iterator it = value.begin(); it != --value.end(); it++)    
    {    
        map<int, int>::iterator next = it;        
        next++;
        maxSet = max(maxSet,it->second + ((abs(it->first-next->first)>1)?0:(next->second)));
    }
    
    
    cout << maxSet;
    
    return 0;
}
