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


bool contains7(int x){
    while(x){
        int rem = x%10;
        if(rem == 7){
            return true;
        }

        x = x/10;
    }

    return false;
}

void solve(){

    int n;
    cin>>n;

    int num = 9;
    int res = 1e9;


    while (num <= 99999999999)
    {
        int cnt = 0;
        int x = n;

        while (!contains7(x))
        {
            x= x + num;
            cnt++;
        }

        res = min(res, cnt);
        num = num*10 + 9;
    }
    


    cout<<res<<endl;

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