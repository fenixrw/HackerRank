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
    vector<int> s(n);
    
    for(int i=0; i<n; i++){
        cin >> s[i];
    }
    
    sort(s.begin(),s.end());
    
    int count = 0;
	
    for(int i=0; i<n-1; i++)
    {
        if(s[i]==s[i+1])
        {
            count++;
            i++;
        }
    }
        
    cout << count;
    
    return 0;
}
