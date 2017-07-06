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

vector<int> array_left_rotation(vector<int> a, int n, int d) {
    
    int p = -d;
    if(p<0)
        p=(n-abs(p%n))%n;
    if(p>=n)
        p=p%n;
    
    if(p==0)
    {
        return a;
    }
    
    vector<int> b(n);
    
    for(int i=0; i<n; i++){
        p = (i-d);
        if(p<0)
            p=(n-abs(p%n))%n;
        if(p>=n)
            p=p%n;
        b[p] = a[i];
    }
    return b;
}

int main(){
    int n;
    int d;
    cin >> n >> d;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    vector<int> output = array_left_rotation(a, n, d);
    for(int i = 0; i < n;i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}
