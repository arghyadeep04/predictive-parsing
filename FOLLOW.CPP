#include<bits/stdc++.h>

#ifndef FOLLOW
#define FOLLOW

#include"FIRST.CPP"
using namespace std;

namespace follow_calc{

    using namespace utils;

    set<char>follow(char x,map<char,set<string>>&productions,char start){
        set<char>ans;
        if(x==start){
            ans.insert('$');
        }
        for(auto p:productions){
            for(auto s:p.second){
                for(int i=0;i<s.length();i++){
                    if(s[i]==x){
                        auto now=first_calc::first(s.substr(i+1),productions);
                        if(now.find('\0')!=now.end()){
                            now.erase('\0');
                            if(p.first!=x){
                                now=unionset(now,follow(p.first,productions,start));
                            }
                        }
                        ans=unionset(ans,now);
                    }
                }
            }
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
//     char st;cin>>st;
//     for(auto p:prods){
//         cout<<p.first<<" : ";
//         auto fi=first_calc::first(string({p.first}),prods);
//         auto fo=follow_calc::follow(p.first,prods,st);
//         for(auto f:fi)cout<<(f=='\0'?"eps":string({f}))<<", ";
//         cout<<"\t";
//         for(auto f:fo)cout<<f<<", ";
//         cout<<endl;
//     }
// }

/*
8
E TX
X +TX
X eps
T FY
Y *FY
Y eps
F (E)
F i
E
*/