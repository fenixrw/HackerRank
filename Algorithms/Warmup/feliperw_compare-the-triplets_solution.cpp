#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int pA = 0, pB = 0;
    vector<int> A(3),B(3);
    for(int i=0; i<3; i++)
    {
        cin >> A[i];
    }
        
    for(int i=0; i<3; i++)
    {
        cin >> B[i];
        
        if(A[i] > B[i])
        {
            pA++;
        }
        else if(A[i] < B[i])
        {
            pB++;
        }
    }
    
    cout << pA << " " << pB;
    return 0;
}
