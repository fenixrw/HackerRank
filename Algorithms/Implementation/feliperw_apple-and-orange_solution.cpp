#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isInside(int val, int s, int t)
{
    return (val>=s && val<=t);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long s,t,a,b,m,n;
    cin >> s >> t >> a >> b >> m >> n;
    
    long apples = 0, oranges = 0;
    
    for(int i=0;i<m;i++)
    {
        long appleDist;
        cin >> appleDist;
        appleDist+=a;
        if(isInside(appleDist,s,t))
            apples++;
    }
    
    for(int i=0;i<n;i++)
    {
        long orangeDist;
        cin >> orangeDist;
        orangeDist+=b;
        if(isInside(orangeDist,s,t))
            oranges++;
    }
    
    cout << apples << endl << oranges;
    return 0;
}
