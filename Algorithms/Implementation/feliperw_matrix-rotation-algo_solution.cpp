#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void rotate(vector<vector<long>> m, long lL, long lR, long lU, long lD, long Rot, vector<vector<long>> &out)
{
    if((lR - lL) < 1 || (lD - lU) < 1)
        return;
    
    long setSize = 2*(lR - lL) + 2 * (lD - lU);
    long reducedRotation = Rot%setSize;
    queue<long> q1,q2;
    
    for(int c=lL;c<lR;c++)
    {
        q1.push(m[lU][c]);
    }
    for(int r=lU;r<lD;r++)
    {
        q1.push(m[r][lR]);
    }
    for(int c=lR;c>lL;c--)
    {
        q1.push(m[lD][c]);
    }
    for(int r=lD;r>lU;r--)
    {
        q1.push(m[r][lL]);
    }
    for(int rr=0;rr<reducedRotation;rr++)
    {
        long temp = q1.front();
        q1.pop();
        q1.push(temp);
    }    
    for(int c=lL;c<lR;c++)
    {
        out[lU][c] = q1.front();
        q1.pop();
    }
    for(int r=lU;r<lD;r++)
    {
        out[r][lR] = q1.front();
        q1.pop();
    }
    for(int c=lR;c>lL;c--)
    {
        out[lD][c] = q1.front();
        q1.pop();
    }
    for(int r=lD;r>lU;r--)
    {
        out[r][lL] = q1.front();
        q1.pop();
    }
    
    rotate(m,lL+1,lR-1,lU+1,lD-1,Rot,out);
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int m, n;
    long r;
    cin >> m >> n >> r;
    
    //m rows & n columns
    vector<vector<long>> v(m,vector<long>(n));
    vector<vector<long>> result(m,vector<long>(n));
    
    for(int row=0; row<m; row++)
    {
        for(int col=0;col<n;col++)
        {
            cin >> v[row][col];
        }
    }
    
    rotate(v,0,n-1,0,m-1,r,result);
    
    for(int row=0; row<m; row++)
    {
        for(int col=0;col<n;col++)
        {
            cout << result[row][col] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
