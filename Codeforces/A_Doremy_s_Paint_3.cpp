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

    int n;
    cin>>n;

    vector<int> b(n); 
    int sum = 0;

    for(int i = 0; i<n; i++){
        cin>>b[i];
        sum+= 2*b[i];
    }

    if(n<=2){
        cout<<"Yes"<<endl;
        return;
    }

    map<int, int> mp;

    for(auto it: b){
        mp[it]++;
    }

    if(mp.size() > 2){
        cout<<"No"<<endl;
        return;
    }

    if(mp.size() == 1){
        cout<<"Yes"<<endl;
        return;
    }

    int x, y;
    int cnt = 0;

    for(auto it: mp){
        if(cnt == 0){
            x = it.second;
        }

        else{
            y = it.second;
        }

        cnt++;
    }

    if(n%2 == 0){
        if(x == y){
            cout<<"Yes"<<endl;
        }

        else{
            cout<<"No"<<endl;
        }
    }

    else{
        if(abs(x-y) > 1){
            cout<<"No"<<endl;
        }

        else{
            cout<<"Yes"<<endl;
        }
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