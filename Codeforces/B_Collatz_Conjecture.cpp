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

    int x, y, k;
    cin>>x>>y>>k;

    if(y == 1){
        cout<<x+k<<endl;
        return;
    }
    
    while(k){
        int rem = x%y;
        int add = y-rem;

        if(k>=add){
            x = x+add;
            k = k-add;
        }

        else{
            x = x+k;
            k = 0;
        }
        while (x%y == 0)
        {
            x = x/y;
        }

        if(x == 1){
            break;
        }
    
    }

    if(k){
        k = k%(y-1);
        x = x+k;
    }

    cout<<x<<endl;
    
    
    
    
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