#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string time;
    cin >> time;
    
    int h = stoi(time.substr(0,2));
    int m = stoi(time.substr(3,2));
    int s = stoi(time.substr(6,2));
    
    if(time[8] == 'P')
    {
        if(h != 12)
            h = (h+12);
    }
    else if(h == 12)
    {
        h = 0;
    }
    
    cout << setfill('0') << setw(2)  << h << ":" << setfill('0') << setw(2) << m  << ":" << setfill('0') << setw(2) << s;
    
    return 0;
}
