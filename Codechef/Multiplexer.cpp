#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9+7;
#define endl '\n'
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>



using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long




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


int f(int idx, int flag, int multip,  vector<int> &a,  map<int, int> &mp, set<pair<int, int>, greater<pair<int, int>>> &st, vector<vector<int>> &dp){
    
    int n = a.size();

    if(idx == n || flag ==2){
        auto it = st.begin();
        return it->first;
    }

    if(dp[idx][flag] != -1){
        return dp[idx][flag];
    }

    int p1, p2, p3;
    p1 = p2 = p3 = 0;

    if(flag == 0){
        //flag0
        p1 = f(idx+1, flag, multip, a, mp, st, dp); //move on
    }
        //flag1
        int x = a[idx];
        int freq = mp[a[idx]];
        auto it1 = st.find({freq, a[idx]});
        auto it2 = st.find({freq, a[idx]*multip});

        mp[x]--;
        st.erase(it1);
        st.insert({mp[x], x});

        a[idx] = a[idx]*multip; //change the array
        mp[a[idx]]++;

        if(it2 == st.end()){
            st.insert({mp[a[idx]], a[idx]});
        }

        else{
            st.erase(it2);
            st.insert({mp[a[idx]], a[idx]});
        }

        p2 = f(idx+1, 1, multip, a, mp, st, dp);

        auto it3 = st.find({mp[x], x});
        auto it4 = st.find({mp[x*multip], x*multip});
        a[idx] = a[idx]/multip;
        mp[x]++;
        mp[x*multip]--;

        st.erase(it3);
        st.erase(it4);

        st.insert({mp[x], x});
        st.insert({mp[x*multip], x*multip});

        p3 = f(idx+1, 2, multip, a, mp, st, dp);


        return dp[idx][flag] =  max({p1, p2, p3});
        
    
}

void solve(){

    int n, x;
    cin>>n>>x;

    vector<int> a(n);
    map<int, int> mp;

    for(int i = 0; i<n; i++){
        cin>>a[i];
        mp[a[i]]++;
    }

    set<pair<int, int>, greater<pair<int, int>>> st;

    for(auto it: mp){
        st.insert({it.second, it.first});
    }

    if(x == 1){
        auto it = st.begin();
        cout<<it->first<<endl;
        return;
    }

    vector<vector<int>> dp(n+1, vector<int> (3, -1));

    // for(auto it: st, dp){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }

    cout<<f(0, 0, x, a, mp, st, dp)<<endl;
    
    
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