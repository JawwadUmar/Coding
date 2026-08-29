#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
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

    string lexGreaterPermutation(int idx, string &target, map<char, int> &mp){

        if(idx == target.size()){
            return "";
        }
        
        if(mp[target[idx]] > 0){
            mp[target[idx]]--;
            string p1 = string(1, target[idx]) + lexGreaterPermutation(idx+1, target, mp);
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

    bool isAnagram(string &s1, string &s2){
        vector<int> v(26, 0);
        for(char ch: s1){
            v[ch-'a']++;
        }
        for(char ch: s2){
            v[ch-'a']--;
        }
        for(int x: v){
            if(x!= 0){
                return false;
            }
        }

        return true;
    }
    
public:
    
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        string targetSubstr = target.substr(0, n/2);
        
        

        map<char, int> mp;
        for(char x: s){mp[x]++;}
        int cnt = 0;
        char oddChar = '0';
        for(auto &it: mp){
            if(it.second%2){
                cnt++;
                oddChar = it.first;
                if(cnt > 1){
                    return "";
                }
            }
            it.second/=2;
        }

        //CASE OF EQUAL PERM FOR HALF THE STRING
        string possiblePalindromeLeft = targetSubstr;
        string possiblePalindromeRight = possiblePalindromeLeft;
        reverse(possiblePalindromeRight.begin(), possiblePalindromeRight.end());
        if(oddChar != '0'){
            possiblePalindromeLeft.push_back(oddChar);
        }
        string possiblePalindrome = possiblePalindromeLeft + possiblePalindromeRight;
        
        
        if(possiblePalindrome > target && isAnagram(s, possiblePalindrome)){
            
            return possiblePalindrome;
        }

        string leftString = lexGreaterPermutation(0, targetSubstr, mp);
        
        string rightString = leftString;
        reverse(rightString.begin(), rightString.end());

        if(oddChar != '0'){
            leftString.push_back(oddChar);
        }

        possiblePalindrome = leftString + rightString;
        if(possiblePalindrome > target && isAnagram(s, possiblePalindrome)){
            return possiblePalindrome;
        }

        return "";

    }
};  

// "baba"
// "abba"