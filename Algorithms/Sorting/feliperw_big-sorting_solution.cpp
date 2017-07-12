#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//12000
//11000

bool comparator(string s1, string s2)
{
    if(s1.size() == s2.size())
    {
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==s2[i])
            {
                continue;
            }
            return (s1[i]<s2[i]);
        }
        
        return false;
    }
    else
    {
        return (s1.size() < s2.size());
    }
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin >> n; 
    vector<string> str(n);
    for(int i=0;i<n;i++)
        cin >> str[i];
    
    sort(str.begin(),str.end(),comparator);
    
    for(int i=0;i<n;i++)
        cout << str[i] << endl;
    
    
    return 0;
}
