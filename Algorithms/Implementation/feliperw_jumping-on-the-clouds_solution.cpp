#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    vector<short> clouds(n);
    
    for(int i=0;i<n;i++)
    {
        cin >> clouds[i];
    }
    
    int jumps = 0;
    
    for(int i=0;i<n-1;i++)
    {
        cin >> clouds[i];
        jumps++;
        
        if(clouds[i+1]==1)
        {
            i++;
        }
        else if(i<n-2)
        {
            if(clouds[i+2]==0)
            {
                i++;
            }
        }
    }
    
    cout << jumps;
    
    return 0;
}
