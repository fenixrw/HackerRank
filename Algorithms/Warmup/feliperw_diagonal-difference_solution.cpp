#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
  0 1 2
0
1
2
*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    long long d1=0, d2=0;
    
    cin >> n;
    
    for(int i=0;i<n;i++)//line
        for(int j=0;j<n;j++)//column
        {
            long long temp;
            cin >> temp;
            if(j==i)
                d1+= temp;
            if(j == (n-1)-i)
                d2+=temp;
        }
    
    cout << abs(d1-d2);
    return 0;
}
