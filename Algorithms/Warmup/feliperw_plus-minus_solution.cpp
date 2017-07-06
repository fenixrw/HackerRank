#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    int pos = 0, neg = 0, zer = 0;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int temp;
        cin >> temp;
        if(temp>0)
        {
            pos++;
        }
        else if(temp<0)
        {
            neg++;
        }
        else
        {
            zer++;
        }
    }
    cout << std::setprecision(6) << std::fixed;
    cout << (float)pos/n << endl << (float)neg/n << endl << (float)zer/n << endl;
    return 0;
}
