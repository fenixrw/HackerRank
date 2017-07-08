#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class CloudJump
{
    int energy, n, k;
    vector<short> clouds;    
    
    bool Jump(int &position)
    {
        energy--;
        int pos = (position+k)%n;
        if(clouds[pos]==1)
            energy-=2;
        
        position = pos;
        
        if(pos == 0)
        {
            return false;
        }
        
        return (energy>=0);
    }
    
    public:
    CloudJump(){
        cin >> n >> k;
        clouds.resize(n);
        for(int i=0;i<n;i++)
        {
            cin >> clouds[i];
        }
    }
    ~CloudJump(){}
    
    int Play()
    {
        energy = 100;
        int position = 0;
        
        while(Jump(position) != 0)
        {
            if(energy <= 0)
            {
                energy = 0;
                break;
            }
        }
        
        return energy;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    CloudJump game;
    cout << game.Play();
    return 0;
}
