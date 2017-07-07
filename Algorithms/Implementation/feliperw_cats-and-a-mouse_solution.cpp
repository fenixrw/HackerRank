#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    
    int n,x,y,z;
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        cin >> x >> y >> z;
        int A = abs(x-z), B = abs(y-z);
        
        cout << ((A<=B)?((A<B)?("Cat A"):("Mouse C")):("Cat B")) << endl;
    }
    
    return 0;
}
