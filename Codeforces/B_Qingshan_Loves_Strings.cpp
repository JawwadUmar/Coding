#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
#define endl '\n'

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

//ctrl shift B for output

int numberOfSetBits(int n){
    return __builtin_popcount(n);
}

bool isGood(string &s){
    int n = s.size();

    for(int i = 1; i<n; i++){
        if(s[i] == s[i-1]){
            return false;
        }
    }

    return true;
}


void solve(){

    int n, m;
    cin>>n>>m;

    string s, t;
    cin>>s;
    cin>>t;

    if(isGood(s)){
        cout<<"Yes"<<endl;
        return;
    }

    if(!isGood(t)){
        cout<<"No"<<endl;
        return;
    }

    int mis_type1 = 0;
    int mis_type2 = 0;

    for(int i = 1; i<n; i++){
        if(s[i] == s[i-1]){
            if(s[i] == '0'){
                mis_type1 = 1;
            }

            else{
                mis_type2 = 1;
            }
        }
    }

    if(mis_type1 ==1 && mis_type2 ==1){
        cout<<"No"<<endl;
        return;
    }

    if(mis_type1 == 1){
        if(t[0] == '1' && t.back() == '1'){
            cout<<"Yes"<<endl;
        }

        else{
            cout<<"No"<<endl;
        }

        return;
    }

    if(mis_type2 ==1){
         if(t[0] == '0' && t.back() == '0'){
            cout<<"Yes"<<endl;
        }

        else{
            cout<<"No"<<endl;
        }

        return;
    }



    
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t = 1;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}