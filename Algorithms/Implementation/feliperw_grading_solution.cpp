#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++)
    {
        int grade;
        cin >> grade;
        
        if(grade >= 38 && grade%5 >= 3)
        {
            grade = grade + (5 - grade%5);
        }
        
        cout << grade << endl;
    }
    
    return 0;
}
