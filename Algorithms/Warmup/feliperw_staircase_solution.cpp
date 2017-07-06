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
    for(int i=0; i< n; i++)
    {
        for(int j=0; j< (n-1)-i; j++)
        {
            cout << " ";
        }
        
        for(int j=0; j< i+1; j++)
        {
            cout << "#";
        }
        cout << endl;
    }
    return 0;
}
