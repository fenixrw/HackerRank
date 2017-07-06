#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Dictionary{
    map<char, Dictionary*> c;
    bool isWord;
    int wordCount;
    public:
    Dictionary(){        
        isWord = false;
    }
    
    bool find(char val){
        
        auto it = c.find(val);
        return (it!=c.end());
    }
    
    void add(string val){
        wordCount++;
        if(val.length() == 0){
            isWord = true;
        }
        else{
            if(find(val[0])){
                char temp = val[0];
                val.erase (val.begin());
                c[temp]->add(val);
            }
            else{
                char temp = val[0];
                val.erase (val.begin());
                c[temp] = new Dictionary();
                c[temp]->add(val);
            }
        }
    }
    
    int countWords(){
        std::map<char,Dictionary*>::iterator it;
        int n = (isWord)?1:0;
        for (it=c.begin(); it!=c.end(); ++it)
            n+= it->second->countWords(); 
        return n;
    }
    
    int find(string val){
        int n = (isWord)?1:0;
        if(val.length() == 0){
            return wordCount;
        }
        else if(find(val[0])){
            char temp = val[0];
            val.erase (val.begin());
            return c[temp]->find(val);
        }
        else
            return 0;
             
        return wordCount;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin >> n;
    string command, word;
    Dictionary d;
    for(int i=0;i<n;i++){
        cin >> command;
        if(command.compare("add") == 0){
            cin >> word;
            //transform(word.begin(), word.end(), word.begin(), ::tolower);
            d.add(word);
        }
        if(command.compare("find") == 0){
            cin >> word;
            //transform(word.begin(), word.end(), word.begin(), ::tolower);
            cout << d.find(word) << endl;
        }
    }
    return 0;
}
