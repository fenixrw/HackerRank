#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    long tallest = 0, sum = 0;
    
    for(int i=0; i<n; i++)
    {
        long temp;
        cin >> temp;
        if(temp == tallest)
            sum++;
        else if(temp > tallest)
        {
            tallest = temp;
            sum = 1;
        }
    }
    
    cout << sum;
    
    return 0;
}
