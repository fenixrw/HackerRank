#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> a;
    cout.setf(ios::fixed);
    int temp;
    
    for(int a_i = 0;a_i < n;a_i++){
       cin >> temp;
       
        auto upper = std::upper_bound(a.begin(), a.end(), temp);
    
        a.insert(upper, temp);
        
       if(a.size()%2 == 0){
           int n1, n2;
           n1 = a.size()/2;
           n2 = n1-1;
        cout << fixed << setprecision(1) << (double)((a[n1]+a[n2])/2.f) << endl;
       }
       else{
        cout << fixed << setprecision(1) << (double)a[a.size()/2] << endl;
       }
        
        
    }
    return 0;
}
