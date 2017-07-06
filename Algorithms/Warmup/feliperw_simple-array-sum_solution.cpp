#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
	long sum = 0;
    cin >> n;
    vector<int> array(n);
    for(int i=0;i<n;i++)
    {
        cin >> array[i];
        sum+=array[i];
    }
    cout << sum;
    return 0;
}
