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

    int n, x;
    cin>>n>>x;

    vector<int> a(n);
    vector<int> pref(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    pref[0] = a[0];
    for(int i = 1; i<n; i++){
        pref[i] = pref[i-1] + a[i];
    }



    vector<int> dp(n, 0);

    if(a.back() <= x){
        dp[n-1] = 1;
    }

    for(int i = n-2; i>=0; i--){
        //index j when sum > x
        int prev = 0;
        if(i-1 >=0){
            prev = pref[i-1];
        }
        auto it = upper_bound(pref.begin(), pref.end(), prev + x); //Binary Search 
        
        int j = it - pref.begin();

            if(j+1 < n){
                dp[i] = j-i + dp[j+1];
            }


            else{
                dp[i] = j-i;
            }
            
        }

    int res = 0;

    for(auto it: dp){
        res+=it;
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