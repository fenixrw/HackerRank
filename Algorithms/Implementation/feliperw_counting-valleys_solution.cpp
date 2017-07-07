#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    string s;
    cin >> n;
    cin >> s;
    
    int level = 0;
    int count = 0;
    bool isValley = false;
    
    for(int i=0; i<n; i++)
    {
        level += ((s[i]=='U')?(1):(-1));
        
        if(isValley && level==0)
        {
            count++;
        }
        
        isValley = (level < 0);
    }
    
    cout << count;
    
    return 0;
}
