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
    int n, m;
    cin>>n>>m;

    vector<string> v;

    for(int i = 0; i<n; i++){
        string s;
        cin>>s;
        v.push_back(s);
    }

    string res = "";
    string vika = "vika";
    int idx = 0;

    for(int j = 0; j<m; j++){
        for(int i = 0; i<n; i++){
            
            if(v[i][j] == vika[idx]){

                idx++;
                break;
            }
        }

        if(idx ==4){
            break;
        }
    }

    if(idx >= 4){
        cout<<"YES"<<endl;
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