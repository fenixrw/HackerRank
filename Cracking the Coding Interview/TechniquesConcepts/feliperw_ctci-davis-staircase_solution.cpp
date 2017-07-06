#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class CountingStairs
{

    static vector<long> savedResults;
    
    static long waysToClimb(int height, int steps)
    {
        int h = height-steps;
        if(h < 0)
            return 0;
        
        if(savedResults[h]>=0)
            return savedResults[h];

        long result = waysToClimb(h,1)+ waysToClimb(h,2) + waysToClimb(h,3);
        savedResults[h]=result;
        
        return result;
        
    }
    
    public:
        
    static void Init(){
        if(savedResults.size()!=36)
        {
            savedResults.resize(36);
            for(int i=0;i<36;i++)
                savedResults[i]=-1;
            savedResults[0] = 1;            
        }
    }

    static int waysToClimb(int h)
    {
        return waysToClimb(h,1)+ waysToClimb(h,2) + waysToClimb(h,3);
    }
};

vector<long> CountingStairs::savedResults;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    CountingStairs::Init();
    int s, n;
    cin >> s;
    for(int i=0;i<s;i++)
    {
        cin >> n;
        cout << CountingStairs::waysToClimb(n) << endl;
    }
    return 0;
}
