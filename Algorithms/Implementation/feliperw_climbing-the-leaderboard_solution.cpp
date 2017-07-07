#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    stack<unsigned long long> rank_score;
    
    unsigned long long n,m;
    cin >> n;
    
    for(unsigned long long i=0; i<n;i++)
    {
        unsigned long long score;
        cin >> score;
        if(rank_score.empty())
        {
            rank_score.push(score);
        }
        else if(rank_score.top() != score)
        {
            rank_score.push(score);
        }
    }
    
    cin >> m;
    
    for(unsigned long long i=0; i<m;i++)
    {
        unsigned long long aliceScore;
        cin >> aliceScore;
        
        unsigned long long rank = 1;
        
        while(!rank_score.empty())
        {
            if(aliceScore > rank_score.top())
            {
                rank_score.pop();
            }
            else
            {
                rank = rank_score.size();
                if(aliceScore < rank_score.top())
                {
                    rank++;
                }
                break;
            }
        }
        
        cout << rank << endl;
    }
    
    return 0;
}
