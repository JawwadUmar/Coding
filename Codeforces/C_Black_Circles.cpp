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

int calculateDistance(int x1, int y1, int x2, int y2){
    int X = (x1-x2)*(x1-x2);
    int Y = (y1-y2)*(y1-y2);

    return X+Y;
}

void solve(){

    int n;
    cin>>n;

    vector<pair<int, int>> v;

    for(int i = 0; i<n; i++){
        int x, y;
        cin>>x>>y;

        v.push_back({x, y});
    }

    int xs, ys, xt, yt;
    cin>>xs>>ys>>xt>>yt;
    
    int d = calculateDistance(xs, ys, xt, yt);

    for(auto it: v){
        int x = it.first;
        int y = it.second;

        if(d >= calculateDistance(xt, yt, x, y)){
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