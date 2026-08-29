#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findJustGreaterCharacter(char ch, map<char, int> &mp){
        for(auto it: mp){
            if(it.first > ch && it.second > 0){
                return it.first;
            }
        }

        return '0';
    }

    string smallestString(map<char, int> &mp){
    string res;
    for(auto it: mp){
        for(int i = 0; i < it.second; i++){
            res.push_back(it.first);
        }
    }
    return res;
}

    string f(int idx, string &target, map<char, int> &mp){

        if(idx == target.size()){
            return "";
        }
        
        if(mp[target[idx]] > 0){
            mp[target[idx]]--;
            string p1 = string(1, target[idx]) + f(idx+1, target, mp);
            mp[target[idx]]++;
            if(p1 > target.substr(idx)){
                
                return p1;
            }
        }
        
        char justGreaterCharacter = findJustGreaterCharacter(target[idx], mp);
        if(justGreaterCharacter == '0'){
            return "";
        }
        mp[justGreaterCharacter]--;
        return string(1, justGreaterCharacter) + smallestString(mp);
    }
    string lexGreaterPermutation(string s, string target) {
        map<char, int> mp;
        for(char x: s){mp[x]++;}

        return f(0, target,mp);
        
    }
};