#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unsigned int n;
    cin >> n;
    unsigned int s, hScore, lScore, hScoreCount=0, lScoreCount=0;
    cin >> s;
    hScore = lScore = s;
    
    for(int i=1; i<n; i++)
    {
        cin >> s;
        if(s>hScore)
        {
            hScore = s;
            hScoreCount++;
        }else if(s<lScore)
        {
            lScore = s;
            lScoreCount++;
        }
    }
    
    cout << hScoreCount << " " << lScoreCount;
    return 0;
}
