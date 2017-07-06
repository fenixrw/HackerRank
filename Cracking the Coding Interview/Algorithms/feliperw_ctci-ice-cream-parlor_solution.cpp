#include <bits/stdc++.h>
using namespace std;

class IceCream {
    
    public: 
        int cost; 
        int index;

        IceCream(int _cost, int _index) {
            cost = _cost;
            index = _index;
       }
};
    
int binarySearch(int first, int last, vector<IceCream> arr, int search) {
        
    int i = (first+last)/2;
    
    if(i==first || i==last)
    {
        if(arr[first].cost==search)
        {
            return arr[first].index;
        }
        
        if(arr[last].cost==search)
        {
            return arr[last].index;
        }
        
        return -1;
    }
    
    if(arr[i].cost<search)
    {
        return binarySearch(i,last,arr,search);
    }
    else if(arr[i].cost>search)
    {
        return binarySearch(first,i,arr,search);
    }
    else if(arr[i].cost==search)
    {
        while(true)
        {
            if(i<=first)
                break;
            if(arr[i-1].cost==search)
                i--;
            else
                break;
        }
        
        return arr[i].index;
    }
    
    return -1;
}

bool compare(IceCream a, IceCream b)
{
    if(a.cost == b.cost)
        return (a.index<b.index);
    return (a.cost < b.cost);
}

int main() {
    int t;
    int n, m;
    cin >> t;
    for(int test = 0; test < t; test++) {       
        cin >> m >> n;
        vector<IceCream> arr;
        arr.reserve(n); 

        for (int i = 0; i < n; i++) {
            int cost;
            cin >> cost;
            arr.push_back(IceCream(cost, i + 1));
        }

        sort(arr.begin(), arr.end(), compare);
        
        for(int i = 0; i < n - 1 ; i++) {
            int search = m - arr[i].cost;
            if(search >= arr[i].cost) {
                int index = binarySearch( i + 1, n - 1, arr, search);
                if( index != -1 ) {
                    cout << min(arr[i].index, index) << " " << max(arr[i].index, index) << endl;
                    break;

                }
            }
        }

    }

}

