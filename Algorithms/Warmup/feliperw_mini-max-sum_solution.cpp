#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long long sumMin = std::numeric_limits<long long>::max(), sumMax = std::numeric_limits<long long>::min();
    
    long long array[5];
    
    for(int i=0; i<5; i++)
    {
        cin >> array[i];
    }
        
    for(int i=0; i<5; i++)
    {
        long long sum = 0;
        for(int j=0; j<5; j++)
        {
            if(j==i)
                continue;
            
            sum+= array[j];
        }
        
        if(sum < sumMin)
            sumMin = sum;
        
        if(sum > sumMax)
            sumMax = sum;
    }
    
    cout << sumMin << " " << sumMax;
    
    return 0;
}
