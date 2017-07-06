#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Node
{
    public:
    int value;
    bool visited;
    
    Node()
    {
        value = 0;
        visited = false;
    }
    
    Node(int val)
    {
        value = val;
        visited = false;
    }
};

int get_region_size(int grid_i, int grid_j, vector< vector<Node> > &grid)
{
    int result = 0;
    grid[grid_i][grid_j].visited = true;
    
    if(grid[grid_i][grid_j].value == 1)
    {
        result++;
        int row_limit = grid.size()-1;
        if(row_limit > 0){
            int column_limit = grid[0].size()-1;
            for(int i = max(0, grid_i-1); i <= min(grid_i+1, row_limit); i++){
                for(int j = max(0, grid_j-1); j <= min(grid_j+1, column_limit); j++){
                    if(i != grid_i || j != grid_j){
                        if(!grid[i][j].visited)
                        {
                            result+= get_region_size(i,j,grid);
                        }
                    }
                }
            }
        }
    }
    
    return result;
}

int get_biggest_region(vector< vector<Node> > &grid) {
    int result = 0;
    
    for(int grid_i = 0;grid_i < grid.size();grid_i++){
       for(int grid_j = 0;grid_j < grid[0].size();grid_j++)
       {
           int regionSize = get_region_size(grid_i, grid_j, grid);
           
           if(regionSize > result)
               result = regionSize;
       }
    }
    
    return result;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<Node> > grid(n,vector<Node>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> grid[grid_i][grid_j].value;
       }
    }
    
    cout << get_biggest_region(grid) << endl;
    return 0;
}
