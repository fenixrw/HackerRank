#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<long> liked(n);
    
    liked[0] = 2;
    
    for(int i=1; i<n; i++)
    {
        liked[i]=floor((long double)(liked[i-1]*3)/2);
    }
    
    cout << accumulate(liked.begin(),liked.end(),0);
    
    return 0;
}