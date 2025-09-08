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


//min value of (max(mexA, mexB))
void solve(){
    int n;
    cin>>n;

    vector<int> a(n);
    vector<int> b(n);
    int mx = -1e18;

    for(int i = 0; i<n; i++){
        cin>>a[i];
        mx = max(a[i], mx);
    }

    for(int i = 0; i<n; i++){
        cin>>b[i];
        mx = max(b[i], mx);
    }

    map<int, int> mp1;
    map<int, int> mp2;
    map<int, int> mp;

    for(int x: a){
        mp1[x]++;
        mp[x]++;
    }

    for(int x: b){
        mp2[x]++;
        mp[x]++;
    }

    int mexA = findMex(a);
    int mexB = findMex(b);


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