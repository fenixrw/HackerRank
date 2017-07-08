#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    
    for(int ti=0;ti<t;ti++)
    {
        string s;
        cin >> s;
        long n = stol(s);
        
        unsigned long count = 0;
        long s_size = s.length();
        
        for(int i=0;i<s_size;i++)
        {
            long digit = s[i]-48;
            if(digit!=0)
                if(n%digit==0)
                    count++;
        }
        
        cout << count << endl;
    }
    
    return 0;
}
