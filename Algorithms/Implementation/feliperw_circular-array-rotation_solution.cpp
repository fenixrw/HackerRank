#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    
    for(int i=0;i<q;i++)
    {
        int m;
        cin >> m;
        cout << a[(m+n-k%n)%n] << endl;
    }
    
    return 0;
}