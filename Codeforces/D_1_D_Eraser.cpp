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
    int n, k;
    cin>>n>>k;


    string s;
    cin>>s;

    int i = 0;
    int cnt = 0;

    while (1)
    {
        if(i>=n){
                break;
        }

        if(s[i] == 'B'){
            i+= k;
            cnt++;

            if(i>=n){
                break;
            }
        }

        else{
            i++;
        }

        if(i>=n){
                break;
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