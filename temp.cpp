#include <bits/stdc++.h>
using namespace std;

    int longestCommonPrefix(vector<string>& v) {
        string ans="";
        sort(v.begin(),v.end());
        int n=v.size();
        string first=v[0],last=v[n-1];
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]){
                return ans.size();
            }
            ans+=first[i];
        }

        return ans.size();
    }

    int main(){
      vector<string> v = {"abc", "abd", "ab"};
      cout<<longestCommonPrefix(v);

    }