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

    vector<int> a(n);
    map<int, int> mp;

    for(int i = 0; i<n; i++){
        cin>>a[i];
        mp[a[i]]++;
    }

    bool flag = false;

    for(auto it: mp){
        if(it.second > 1){
            flag = true;
            break;
        }
    }

    if(flag == false){

        cout<<n<<endl;
        return;
    }

    flag = false;
    int cnt = 0;
    int x = 0;

    for(auto it: mp){

        if(it.first != 0){
            cnt+= (it.second)%2;
            x+= (it.second)/2; //no of zeroes produced
        }
        
    }

    // cout<<x<<endl;

    int totalZeroes = x + mp[0];
    if(totalZeroes > 1){
        totalZeroes = 1;
    }

    cout<<cnt + totalZeroes<<endl;

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