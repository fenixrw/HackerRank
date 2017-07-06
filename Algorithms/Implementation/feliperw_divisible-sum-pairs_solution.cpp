#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    
    int count = 0;
    
    for(int i=0;i<n;i++)
        cin >> a[i];
    
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
        {
            if((a[i]+a[j])%k==0)
                count++;
        }
    
    cout << count;
    
    return 0;
}
