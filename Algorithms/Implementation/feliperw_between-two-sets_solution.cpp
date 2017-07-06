#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int nA, nB;
    cin >> nA;
    cin >> nB;
    
    vector<int> A, B;
    
    for(int i=0;i<nA;i++)
    {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }
    
    for(int i=0;i<nB;i++)
    {
        int temp;
        cin >> temp;
        B.push_back(temp);
    }
    
    int count = 0;
    
    for(int i=A[A.size()-1]; i<= B[0];i++)
    {
        bool skip = false;
        
        for(int j=0;j<A.size();j++)
        {
            if(i%A[j] != 0)
            {
                skip = true;
                break;
            }
        }
        
        if(skip)
            continue;
        
        for(int j=0;j<B.size();j++)
        {
            if(B[j]%i!=0)
            {
                skip = true;
                break;
            }
        }
        
        if(skip)
            continue;
        
        count++;
    }
    
    cout << count;
    
    return 0;
}
