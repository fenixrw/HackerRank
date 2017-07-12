#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

    const string ones[21] = {"", "one", "two", "three","four","five","six","seven",
    "eight","nine","ten","eleven","twelve","thirteen","fourteen","quarter","sixteen","seventeen",
    "eighteen","nineteen", "twenty"};

string getMinutes(int n)
{
    stringstream ss;
    if(n == 30)
    {
        ss << "half";
    }
    else if(n == 15)
    {
        ss << "quarter";
    }
    else if(n<=20)
    {
        ss << ones[n] << " minute" << ((n>1)?"s":"");
    }
    else if(n < 30)
    {
        ss << "twenty " << ones[n-20] << " minutes";
    } 
    
    return ss.str();
    
}


int main() {
    
    
    int h,m;
    cin >> h >> m;
    
    if(m==0)
    {
        cout << ones[h] << " o' clock";
    }
    else if(m <= 30)
    {
        cout << getMinutes(m) << " past " << ones[h];
    }
    else
    {
        cout << getMinutes(60-m) << " to " << (((h+1)==13)?ones[1]:ones[h+1]);
    }
    
    
    return 0;
}
