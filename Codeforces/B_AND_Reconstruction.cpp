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
    vector<int> b(n-1);

    for(int i = 0; i<n-1; i++){
        cin>>b[i];
    }

    vector<int> a(n);

    for(int i = n-1; i>=1; i--){
        int target = b[i-1];
        int x = 0;

        for(int j = 0; j<=30; j++){
            if((target>>j)&(1)){
                x = x | (1<<j);
            }
        }

        a[i] = x;
    }

    for(int i = 0; i<n-1; i++){
        int target = b[i];

        for(int j = 0; j<=30; j++){
            if((target>>j)&(1)){
                a[i] = a[i] | (1<<j);
            }
        }
    }

    for(int i = 0; i<n-1; i++){
        int x = a[i]&a[i+1];
        if(b[i] != x){
            cout<<-1<<endl;
            return;
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