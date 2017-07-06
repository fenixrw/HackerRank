#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int n;
    cin >> n;
    int birdCount[5] = {0,0,0,0,0};
    
    for(int i=0;i<n;i++)
    {
        int bird;
        cin >> bird;
        birdCount[bird-1]++;
    }
        
    int highestCount = 0;
    int highestCountId = 0;
    for(int i=0;i<5;i++)
    {
        if(birdCount[i] > highestCount)
        {
            highestCount = birdCount[i];
            highestCountId = i+1;
        }
    }
    
    cout << highestCountId;
    
    
    return 0;
}
