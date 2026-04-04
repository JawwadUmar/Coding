#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fill(string &res, int i, string &str2){
        int idx = 0;
        while (idx < str2.size())
        {
            res[i] = str2[idx];
            idx++;
            i++;
        }  
    }

    void tryMakeItNotEqual(string &res, string &str2, int i){

        int idx = 0;
        while (idx < str2.size())
        {
            if(idx == str2.size()-1){
                if(str2[idx] == 'a'){
                    res[i] = 'b';
                }
                else{
                    res[i] = 'a';
                }
            }

            else if(str2[idx]!= 'a' && res[i] == '*'){
                res[i] = 'a';
                break;
            }

            else if(res[i] == '*'){
                res[i] = 'a';
            }

            i++;
            idx++;
        }
        
    }

    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        string res(n+m-1, '*');

        for(int i = 0; i<n; i++){
            if(str1[i] == 'T'){
                fill(res, i, str2);
            }
        }

        for(int i = 0; i<n; i++){
            if(str1[i] == 'T'){
                string substr = res.substr(i, m);
                if(substr != str2){
                    return "";
                }
            }
        }

        for(int i = 0; i<n; i++){
            if(str1[i] == 'F'){
                tryMakeItNotEqual(res, str2, i);
            }
        }

        for(int i = 0; i<n; i++){
            string substr = res.substr(i, m);
            if(str1[i] == 'T'){
                if(substr != str2){
                    return "";
                }
            }

            else{
                if(substr == str2){
                    return "";
                }
            }
        }

        return res;
    }
};