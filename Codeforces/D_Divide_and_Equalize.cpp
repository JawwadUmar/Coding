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

//ctrl shift B for output

int numberOfSetBits(int n){
    return __builtin_popcount(n);
}




void solve(){

    int n;
    cin>>n;

    unordered_map<int, int> mp;
    
    vector<int> a(n);

    bool flag = false;
    for(int i = 0; i<n; i++){
        cin>>a[i];

        if(i>0){
            if(a[i] != a[i-1]){
                flag = true;
            }
        }
    }

    if(flag == false){
        cout<<"YES"<<endl;
        return;
    }

    for(int i = 0; i<n; i++){
        
        int x = a[i];
        int d = 2;

        while (d*d <= x && x!= 1)
        {
            while (x%d ==0)
            {
                mp[d]++;
                x = x/d;
            }

            d++;
        }

        if(x!= 1){
            mp[x]++;
        }
        
    }

    int prev = -1;

    for(auto it: mp){
        if(it.second % n !=0){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
    
    
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