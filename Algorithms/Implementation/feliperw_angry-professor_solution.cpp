#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t, n, k, s;
    cin >> t;
    for(int ti=0; ti<t;ti++)
    {
        cin >> n >> k;
        int students = 0;
        for(int i=0; i<n; i++)
        {
            cin >> s;
            if(s<=0)
                students++;
        }
        
        cout << ((students>=k)?"NO":"YES") << endl;
    }
    return 0;
}
