#include<bits/stdc++.h>
#include"UTILS.CPP"

#ifndef FIRST
#define FIRST

using namespace std;

namespace first_calc{
    using namespace utils;
    set<char>first(string x,map<char,set<string>>&productions){
        if(x==""){
            return {'\0'};
        }
        if(!isNonTerminal(x[0])){
            return {x[0]};
        }
        set<char>ans;
        for(auto s:productions[x[0]]){
            set<char>cur=first(s,productions);
            if(cur.find('\0')!=cur.end()){
                cur.erase('\0');
                cur=unionset(cur,first(x.substr(1),productions));
            }
            ans=unionset(ans,cur);
        }
        return ans;
    }

}

#endif

// int main(){
//     map<char,set<string>>prods;
//     int n;cin>>n;
//     for(int i=0;i<n;i++){
//         char l;string r;
//         cin>>l>>r;
//         if(r=="eps")r="";
//         prods[l].insert(r);
//     }
//     string s;cin>>s;
//     auto ans=first_calc::first(s,prods);
//     for(auto x:ans){
//         cout<<(x=='\0'?"eps":string({x}))<<", ";
//     }
// }

/*
6
S TabS
S X
T cT
T eps
X b
X bX
X
*/