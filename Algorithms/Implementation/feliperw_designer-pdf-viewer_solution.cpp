#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int h[26];
    for(int i=0;i<26;i++)
        cin >> h[i];
    string word;
    cin >> word;
    
    int highest = 1;
    
    for(int i=0;i<word.length();i++)
    {
        highest = max(highest,h[word[i]-97]);
    }
    
    cout << word.length()*highest;
    
    return 0;
}
