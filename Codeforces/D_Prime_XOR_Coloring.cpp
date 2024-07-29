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

    if(n == 1){
        cout<<"1"<<endl;
        cout<<"1"<<endl;
        return;
    }

    if(n == 2){
        cout<<2<<endl;
        cout<<1<<" "<<2<<endl;
        return;
    }

    if(n == 3){
        cout<<2<<endl;
        cout<<"1 2 2"<<endl;
        return;
    }

    if(n == 4){
        cout<<3<<endl;
        cout<<"1 2 2 3"<<endl;
        return;
    }

    if(n == 4){
        cout<<3<<endl;
        cout<<"1 2 2 3"<<endl;
        return;
    }

    if(n == 5){
        cout<<3<<endl;
        cout<<"1 2 2 3 3"<<endl;
        return;
    }

    if(n == 6){
        cout<<4<<endl;
        cout<<"1 2 2 3 3 4"<<endl;
        return;
    }

    cout<<4<<endl;
    
    for(int i = 1; i<=n; i++){
        cout<<i%4+1<<" ";
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