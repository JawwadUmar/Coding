#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int MOD = 998244353;
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
    vector<int> a(n);

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    vector<int> prefSum(n);
    prefSum[0] = a[0];

    int mn = prefSum[0];

    for(int i = 1; i<n; i++){
        prefSum[i] = prefSum[i-1] + a[i];
        mn = min(mn, prefSum[i]);
    }

    int count = 0;
    int ans = 1;

    if(mn<0){
        // cout<<prefSum.back() + 2*abs(mn)<<endl;

        //how many mns occur ? 
        for(auto it: prefSum){
            if(it == mn){
                count++;
            }
        }

         ans = binaryExponentiation(2, count-1);
    }

    else{
        // cout<<prefSum.back()<<endl;
    }

    //number of ways to get the same answer .... 
    //there were some points where using option 1 and 2 is the same thing
    for(auto it: prefSum){
        if(it >=0){
            ans = (ans*2)%MOD;
        }
    }

    cout<<ans<<endl;

    
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