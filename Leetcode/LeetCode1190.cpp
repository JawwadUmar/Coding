#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {

        stack<char> st;
        int i = 0;

        while(i<s.size()){

            if(s[i] == ')'){
                string temp;
                while(!st.empty() && st.top() != '('){

                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                
                

                for(char ch: temp){
                    st.push(ch);
                }
            }
            else{
                st.push(s[i]);
            }

            i++;
        }

        string res;
        while (!st.empty())
        {
            
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};