#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, p;
    cin >> n >> p;
    int tFront, tBack;
    
    tFront = floor((float)p/2.0f);
    tBack = ((n%2==0)?ceil((float)(n-p)/2.0f):floor((float)(n-p)/2.0f));
    
    cout << min(tFront,tBack);
    
    return 0;
}
