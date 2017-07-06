#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    long long sum = 0;
    cin >> n;
    long long temp;
    for(int i = 0; i<n; i++)
    {
        cin >> temp;
        sum+= temp;
    }
    
    cout << sum;
    
    return 0;
}
