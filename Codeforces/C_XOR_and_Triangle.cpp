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



bool isTriangle(int x, int y, int z){
    if(x+y <= z || x+z <= y || y+z <= x){
        return false;
    }

    return true;
}


void solve(){

    int x;
    cin>>x;

    for(int i = 0; i<31; i++){
        int y = 0;
        int bit = (1<<i)&(x);
        if(bit !=0){
            //Set this bit for y (same as x)
            y = y|(1<<i);

            //Now look for a bit in x that is not set
            for(int j = 0; j<31; j++){
                bit = (1<<j)&(x);
                if(bit == 0){
                    y = y|(1<<j);

                    if(y<x){
                        cout<<y<<endl;
                        return;
                    }
                }
            }
        }
    }

    cout<<-1<<endl;
    
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