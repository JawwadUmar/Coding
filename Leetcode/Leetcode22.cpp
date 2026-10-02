#include <bits/stdc++.h>
using namespace std;

void f(int openBrackets, int closeBrackets, int n, string s, vector<string> &res){
    if(openBrackets == n && closeBrackets==n){
        res.push_back(s);
        return;
    }

    if(openBrackets > n){
        return;
    }

    if(openBrackets == closeBrackets){
        s.push_back('(');
        f(openBrackets+1, closeBrackets, n, s, res);
        return;
    }

    s.push_back('(');
    f(openBrackets+1, closeBrackets, n, s, res);
    s.pop_back();
    s.push_back(')');
    f(openBrackets, closeBrackets+1, n, s, res);
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        f(0, 0, n, "", res);
        return res;
    }
};