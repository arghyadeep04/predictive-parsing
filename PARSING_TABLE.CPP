#include<bits/stdc++.h>
#include"FIRST.CPP"
#include"FOLLOW.CPP"
#include"UTILS.CPP"

using namespace std;

namespace table_calc{
    using namespace utils;
    map<pair<char,char>,set<pair<char,string>>>getParsingTable(map<char,set<string>>&productions,char start){
        map<pair<char,char>,set<pair<char,string>>>table;
        for(auto p:productions){
            for(auto s:p.second){
                set<char>now=first_calc::first(s,productions);
                if(now.find('\0')!=now.end()){
                    now.erase('\0');
                    now=unionset(now,follow_calc::follow(p.first,productions,start));
                }
                for(auto c:now){
                    table[{p.first,c}].insert({p.first,s});
                }
            }
        }
        return table;
    }
}