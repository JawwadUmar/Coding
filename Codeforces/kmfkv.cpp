#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
int binaryExponentiation(int x, int p){
    int res = 1;
    while(p){
        if(p%2){
            res = (res * x)%MOD;
        }

        x = (x*x)%MOD;
        p = p/2;
    }
    
    return res;
}



    bool canMakeSubsequence(string str1, string str2) {
        //str2 subs of str1

        if(str2.size() > str1.size()){
            return false;
        }
        int n = str1.size();
        int m = str2.size();

        int i1 = 0;
        int i2 = 0;
        int last = -1;
        
        while (1)
        {
            if(str1[i1] ==str2[i2]){
                i1++;
                i2++;
                last = i1;
            }

            else{
                i1++;
            }

            if(i2 == m){
                return true;
            }

            if(i1 == n){
                break;
            }

        }

        string temp = str1;

        for(int i = last+1; i<n; i++){
            if(temp[i] != 'z'){
                temp[i] = str1[i] + 1;
            }

            else if(temp[i] =='z'){
                temp[i] = 'a';
            }
        }

        i1 = 0;
        i2 = 0;

        while (1)
        {
            if(temp[i1] ==str2[i2]){
                i1++;
                i2++;
                last = i1;
            }

            else{
                i1++;
            }

            if(i2 == m){
                return true;
            }

            if(i1 == n){
                break;
            }

        }

        i1= 0;
        i2 = 0;
        

        for(int i = 0; i<str1.size(); i++){
            if(str1[i] != 'z'){
                str1[i] = str1[i] + 1;
            }

            else if(str1[i] =='z'){
                str1[i] = 'a';
            }
        }

        

        

        while (1)
        {
            if(str1[i1] == str2[i2]){
                i1++;
                i2++;
            }

            else{
                i1++;
            }

            if(i2 ==m){
                return true;
            }

            if(i1 == n){
                break;
            }
        }

        return false;
    }

void solve(){
    
    string s1 = "ff";
    string s2 = "fg";

    cout<< canMakeSubsequence(s1, s2)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t;
    t=1;
    // cin>>t;
    while(t--){
       solve();
    }
    return 0;
}