#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int ki[2], kv[2];
    for(int i=0;i<2;i++)
    {
        cin >> ki[i];
        cin >> kv[i];
    }
    
    bool willMeet = false;
    
    if((ki[0] < ki[1] && kv[0] > kv[1]) || (ki[0] > ki[1] && kv[0] < kv[1]))
    {
        if((ki[0] - ki[1]) % (kv[1] - kv[0]) == 0)
                willMeet = true;
    }
   
    cout << (willMeet ?"YES":"NO");
    
    return 0;
}
