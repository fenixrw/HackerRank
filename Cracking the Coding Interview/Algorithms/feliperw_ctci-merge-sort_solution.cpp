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

long long merge(vector<int> &a, int startIndex, int endIndex)
{

    long long inversions = 0;

    int size = (endIndex - startIndex) + 1;
    int *b = new int [size]();

    int i = startIndex;
    int mid = (startIndex + endIndex)/2;
    int k = 0;
    int j = mid + 1;

    bool inverted = false;

    while (k < size && i<=mid && j<=endIndex)
    {
        if((a[i] <= a[j]))
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
            inversions+= abs(mid+1-i);
        }

    }
    
    while(i<=mid){
        b[k++] = a[i++];
    }
    
    while(j<=endIndex)
    {
        b[k++] = a[j++];
        inversions+= abs(mid+1-i);
    }

    for(k=0; k < size; k++)
    {
        a[startIndex+k] = b[k];
    }

    delete []b;
    
    return inversions;

}

long long merge_sort(vector<int> &iArray, int startIndex, int endIndex)
{
    long long inversions = 0;
    
    int midIndex;

    if (startIndex >= endIndex)
    {
        return 0;
    }

    //Find mid
    midIndex = (startIndex + endIndex)/2;

    //First half
    inversions += merge_sort(iArray, startIndex, midIndex);
    //Second half
    inversions += merge_sort(iArray, midIndex+1, endIndex);
    //Merge
    inversions += merge(iArray, startIndex, endIndex);
    
    return inversions;

}

long long count_inversions(vector<int> a) {
    
    long long total = merge_sort(a, 0, a.size()-1);
    return total;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0;arr_i < n;arr_i++){
           cin >> arr[arr_i];
        }
        cout << count_inversions(arr) << endl;
    }
    return 0;
}
