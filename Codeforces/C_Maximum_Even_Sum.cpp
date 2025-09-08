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

    int a, b;
    cin>>a>>b;

    //both odd
    if(a%2 != 0 && b%2!= 0){
        cout<<max(a+b, a*b +1)<<endl;
        return;
    }

    //b odd and a even not possible
    if(b%2 != 0 && a%2 ==0){
        cout<<-1<<endl;
        return;
    }

    //a odd and b even
    if(a%2!= 0 && b%2 == 0){

        int pot1 = b/2;
        if(pot1%2){
            cout<<-1<<endl;
            return;
        }

        int pot2 = 2;

        cout<<max(a*pot1 + b/pot1, a*pot2 + b/pot2)<<endl;
        return;

    }

    //a even and b even
    if(a%2 == 0 && b%2 == 0){
        int pot1 = b/2;
        int res = -1;
        if((a*pot1 + b/pot1)%2 == 0){
            res = a*pot1 + b/pot1;
        }

        int pot2 = 2;

        if((a*pot2 + b/pot2)%2 == 0){
            res = max(res, a*pot2 + b/pot2);
        }
        
        cout<<max({res, a+b})<<endl;
        return;
    }

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