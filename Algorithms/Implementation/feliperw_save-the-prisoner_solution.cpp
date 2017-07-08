#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    long n,m,s;
    
    cin >> t;
    
    for(int ti=0;ti<t;ti++)
    {
        cin >> n >> m >> s;
        s--; 
        m--;
        cout << (1+(s+(m%n))%n) << endl;
    }
    
    return 0;
}
