#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
int binaryExponentiation(int x, int p){\
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

int numberOfSetBits(int n){
    return __builtin_popcount(n);
}


string add(int H, int M, string &s){

    string hr = s.substr(0, 2);
    string mint = s.substr(3, 2);

    int hour_in_int = stoi(hr);
    int min_in_int = stoi(mint);

    
    int nmin = (M+ min_in_int)%60;

    int rem = (M+ min_in_int)/60;

    int nhr = (H + hour_in_int + rem)%24;


    string NHR = to_string(nhr);


    if(NHR.size() ==1){
        NHR = "0" + NHR;
    }


    string NMIN = to_string(nmin);

    if(NMIN.size() == 1){
        NMIN = "0" + NMIN;
    }

    return NHR + ":" + NMIN;
}

bool isPalindrome(string &s){

    int i = 0;
    int j = s.size()-1;

    while (j>i)
    {
        if(s[i] != s[j]){
            return false;
        }

        i++;
        j--;
    }

    return true;
    
}


void solve(){

    string s;
    cin>>s;

    int mint;
    cin>>mint;

    int H = mint/60;
    int M = mint%60;

    set<string> st;

    st.insert(s);

    while (1)
    {
        string temp = add(H, M, s);

        if(st.find(temp) != st.end()){
            break;
        }

        st.insert(temp);
        s = temp;
    }


    int cnt = 0;

    for(auto it: st){

        if(isPalindrome(it)){
            cnt++;
        }
    }

    cout<<cnt<<endl;
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t;
    // t=1;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}