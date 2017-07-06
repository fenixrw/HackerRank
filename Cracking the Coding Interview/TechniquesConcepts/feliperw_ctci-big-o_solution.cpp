#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(unsigned int num)
{
    if(num < 2)
        return false;
    if(num==2)
        return true;
    
    if(num%2==0) 
        return false;
    
    for(unsigned int i=3; i*i<=num;i+=2)  
    {
        if(num%i==0)
            return false;
    }
    
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int p;
    cin >> p;
    for(int i=0; i<p;i++)
    {
        int n;
        cin >> n;
        if(isPrime(n))
        {
            cout << "Prime" << endl;
        }
        else
        {
            cout << "Not prime" << endl;
        }
    }
    return 0;
}
