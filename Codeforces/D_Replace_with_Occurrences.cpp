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


void solve(){

    int n;
    cin>>n;

    vector<int> b(n);
    map<int, int> mp;

    for(int i = 0; i<n; i++){
        cin>>b[i];
        mp[b[i]]++;
    }

    for(auto it: mp){
        if((it.second)%(it.first) != 0){
            cout<<-1<<endl;
            return;
        }
    }

    map<int, vector<int>> mp2;
    int x = 1;
    for(auto it: mp){
        int cnt = it.second/it.first;

        for(int i = 0; i<cnt; i++){
            mp2[it.first].push_back(x);
            x++;
        }
    }

    vector<int> a(n);
    map<int, int> freq;
    for(int i = 0; i<n; i++){
        int x = mp2[b[i]].back();
        a[i] = x;
        freq[x]++;

        if(freq[x] == b[i]){
            mp2[b[i]].pop_back();
        }
    }

    for(auto it: a){
        cout<<it<<" ";
    }

    cout<<endl;




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