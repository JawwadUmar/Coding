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

void solve(){
    int n, a, q;
    cin>>n>>a>>q;

    string s;
    cin>>s;


    if(a == n){
        cout<<"YES"<<endl;
        return;
    }

    int i = 0;
    int cnt = a;

    while(i<q){
        if(s[i] == '+'){
            a+=1;
            cnt++;
        }

        else{
            a-=1;
        }

        if(a== n){
            cout<<"YES"<<endl;
            return;
        }

        i++;
    }

    if(cnt >= n){
        cout<<"MAYBE"<<endl;
        return;
    }

    cout<<"NO"<<endl;


    
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