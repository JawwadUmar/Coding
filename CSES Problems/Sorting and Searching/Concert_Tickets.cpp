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

    int n, m;
    cin>>n>>m;

    vector<int> prices(n);

    for(int i = 0; i<n; i++){
        cin>>prices[i];
    }

    multiset<int> st (prices.begin(), prices.end());

    vector<int> mxPrice(m);

    vector<int> res;

    for(int i = 0; i<m; i++){
        cin>>mxPrice[i];

        auto it = st.lower_bound(mxPrice[i]);

        if(*it == mxPrice[i]){
            res.push_back(mxPrice[i]);
            st.erase(it);
            continue;
        }

        else if(it == st.begin()){
            res.push_back(-1);
        }

        else{
            it--;

            res.push_back(*it);

            st.erase(it);
        }
    }


    for(auto it: res){
        cout<<it<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t = 1;
    // cin>>t;
    while(t--){
       solve();
    }
    return 0;
}