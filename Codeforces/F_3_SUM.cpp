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


void solve(){
    int n;
    cin>>n;

    vector<int> a(n);
      map<int, int> mp;

    for(int i = 0; i<n; i++){
        cin>>a[i];

        string s = to_string(a[i]);

        a[i] = s.back() - '0';

        mp[a[i]]++;

    }

    if(mp[1] >=3){
        cout<<"YES"<<endl;
        return;
    }

    vector<int> v;

    for(auto it: mp){
        if(it.second == 1){
            v.push_back(it.first);
        }

        else if(it.second > 1){
            v.push_back(it.first);
            v.push_back(it.first);
        }
    }

    for(int i = 0; i<v.size(); i++){
        for(int j = i+1; j<v.size(); j++){
            for(int k = j+1; k<v.size(); k++){
                
                int sum = v[i] + v[j] + v[k];

                string temp = to_string(sum);

                if(temp.back() == '3'){
                    cout<<"YES"<<endl;
                    return;
                }
            }
        }
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