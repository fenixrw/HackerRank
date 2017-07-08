#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, x;
    cin >> n;
    vector<int> p(n);
    for(int i=0;i<n;i++)
    {
        cin >> x;
        x--;
        p[x] = i;
    }
    
    for(int i=0;i<n;i++)
    {
        cout << (p[p[i]]+1) << endl;
    }
    return 0;
}
