#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long combinations(long k, vector<long long> a) {
    vector<long long> counts(k);
    fill(counts.begin(),counts.end(),0);
    
    for(long i = 0; i < a.size(); i++) {
        counts[a[i]%k]++;
    }
    
    
    /*for(long i = 0; i < counts.size(); i++) {
        cout << counts[i] << " ";
    }*/
    
    if(k%2==0)
        counts[k/2] = min(counts[k/2],(long long)1);
    
    long long count = min(counts[0],(long long)1);
    
    for(int i=1;i<=k/2;i++)
    {
        count+= max(counts[i],counts[k-i]);
    }
    
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long n,k;
    cin >> n >> k;
    vector<long long> a(n);
    
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    
    cout << combinations(k,a);
    
    return 0;
}
