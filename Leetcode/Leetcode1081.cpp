#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    

    string smallestSubsequence(string s) {
        int n = s.size();
        stack<char> st;
        map<char ,int> mp;
        set<char> alreadyPut;
        for(char &ch: s){
            mp[ch]++;
        }

        for(int i = 0; i<n; i++){
            
            if(alreadyPut.count(s[i]) == 0){
                while (s[i] < st.top() && mp[st.top()] > 0){
                    st.pop();
                }
                st.push(s[i]);
            }
            mp[s[i]]--;
            alreadyPut.insert(s[i]);
        }

        s = "";
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }

        reverse(s.begin(), s.end());
        return s;
    }
};