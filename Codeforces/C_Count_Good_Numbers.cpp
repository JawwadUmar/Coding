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

int f(int l, int r, int p){
    
    int x1 = r/p;
    int x2 = l/p;

    int res = x1-x2;

    if(l%p == 0){
        res++;
    }

    return res;
}


void solve(){

    int l, r;
    cin>>l>>r;

    int cnt2 = f(l, r, 2);
    int cnt3 = f(l, r, 3);
    int cnt5 = f(l, r, 5);
    int cnt7 = f(l, r, 7);

    int cnt6 = f(l, r, 6);
    int cnt10 = f(l, r, 10);
    int cnt14 = f(l, r, 14);
    int cnt15 = f(l, r, 15);
    int cnt21 = f(l, r, 21);
    int cnt35 = f(l, r, 35);

    int cnt30 = f(l, r, 30);
    int cnt42 = f(l, r, 42);
    int cnt105 = f(l, r, 105);
    int cnt70 = f(l, r, 70);

    int cnt210 = f(l, r, 210);

    int sum = (cnt2 + cnt3 + cnt5 + cnt7) - (cnt6 + cnt10 + cnt14 + cnt15 + cnt21 + cnt35) + (cnt30 + cnt42 + cnt105+ cnt70) - cnt210;

    cout<<(r-l+1) - sum <<endl;
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