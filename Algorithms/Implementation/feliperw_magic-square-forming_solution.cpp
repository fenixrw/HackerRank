#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Square{
    vector<vector<int>> s;
             
    static int possibleMagic[8][3][3];
             
    public:
             
    Square(vector<vector<int>> _s){ 
        s=_s;
    }
    
    int getMakeMagicCost()
    {
        int bestCost = numeric_limits<int>::max();
        for(int i=0;i<8;i++)
        {
            int cost = 0;
            for(int l=0;l<3;l++)
            {
                for(int c=0;c<3;c++)
                {
                    cost += abs(possibleMagic[i][l][c]-s[l][c]);
                    
                    if(cost > bestCost)
                        break;
                }
                
                if(cost > bestCost)
                    break;
            }
            
            if(cost<bestCost)
                bestCost = cost;
            
            if(bestCost == 0)
            {
                break;
            }
        }
        
        return bestCost;
    }
};

int Square::possibleMagic[8][3][3] = {
            {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
            {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
            {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
            {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}}, 
            {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
            {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}}, 
            {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}}, 
            {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}};
			

int main() {
    
    vector<vector<int>> s(3,vector<int>(3));
    
    for(int l=0;l<3;l++)
    {
        for(int c=0;c<3;c++)
        {
            cin >> s[l][c];
        }
    }
    
    Square magicS(s);
    
    cout << magicS.getMakeMagicCost();
    
    return 0;
}
