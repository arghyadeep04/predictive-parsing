#include<bits/stdc++.h>
using namespace std;

#ifndef UTILS
#define UTILS

namespace utils{
    
    bool isNonTerminal(char x){
        return 'A'<=x && x<='Z';
    }
    set<char>unionset(set<char> a,set<char> b){
        auto ans=a;
        for(auto it:b)ans.insert(it);
        return ans;
    }
}

#endif