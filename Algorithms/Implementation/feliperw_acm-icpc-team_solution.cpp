#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string operator | (const string& s1, const string& s2)
{
    string s = s1;
    for(int i=0; i<s.length();i++)
    {
        s[i] = s1[i] | s2[i];
    }
    return s;
} 

unsigned long long getTeamTopics (const string& s1, const string& s2, unsigned long long&maxTopics)
{
    string s = s1;
    int c = 0;
    for(int i=0; i<s.length();i++)
    {
        s[i] = s1[i] | s2[i];
        if(s[i]=='1')
            c++;
        
        if(maxTopics > (c + (s.length()-i)))
           break;
    }
    return c;
} 

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,m;
    cin >> n >> m;
    vector<string> people(n);
    
    for(int i=0;i<n;i++)
        cin >> people[i];
    
    unsigned long long maxTopics = 0;
    unsigned long long maxTeams = 0;
    
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            unsigned long long topics = getTeamTopics(people[i],people[j],maxTopics);
            if(topics > maxTopics)
            {
                maxTopics = topics;
                maxTeams = 1;
            }
            else if(topics == maxTopics)
            {
                maxTeams++;
            }
        }
    
    cout << maxTopics << endl << maxTeams;
    
    return 0;
}
