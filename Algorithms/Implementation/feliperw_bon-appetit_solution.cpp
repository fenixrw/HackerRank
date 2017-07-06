#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,k,b;
    
    cin >> n >> k;
    
    long long bill = 0;
    
    for(int i=0; i<n; i++)
    {
        int c;
        cin >> c;
        if(i!=k)
        {
            bill+=c;
        }
    }
    
    cin >> b;
    
    if(bill/2 == b)
        cout << "Bon Appetit";
    else
        cout << b-(bill/2);
    
    return 0;
}
