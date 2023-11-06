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


void solve(){

    int n, k;
    cin>>n>>k;

    int posb = (n+1)/2;

    if(k>posb){
        cout<<-1<<endl;
        return;
    }


    vector<vector<char>> v(n, vector<char> (n, '.'));

    int i = 0;
    int j = 0;

    for(int itr = 0; itr<k; itr++){
        v[i][j] = 'R';
        i+=2;
        j+=2;
    }

    for(int i = 0; i<n; i++){
        for(j = 0; j<n; j++){
            cout<<v[i][j];
        }
        cout<<endl;
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