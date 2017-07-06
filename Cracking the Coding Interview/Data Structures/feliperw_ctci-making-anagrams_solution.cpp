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

//'a' = 97 | total characters = 26

int number_needed(string a, string b) {
    
    int charCounterA[26],charCounterB[26], n = 0; 
    
    for(int i=0; i < 26; i++){
        charCounterA[i]=0;
        charCounterB[i]=0;
    }
    for(int i=0; i < a.length(); i++){
        charCounterA[a[i]-97]++;
    }
    for(int i=0; i < b.length(); i++){
        charCounterB[b[i]-97]++;
    }
    for(int i=0; i < 26; i++){
        n += abs(charCounterA[i]-charCounterB[i]);
    }
   
    return n;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
