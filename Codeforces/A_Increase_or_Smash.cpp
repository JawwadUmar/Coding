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

bool allEmementZero(vector<int> &a){
    for(int x: a){
        if(x != 0){
            return false;
        }
    }

    return true;
}

void solve(){

    int n;
    cin>>n;

    bool flag = true;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];

        if(a[i] != 0){
            flag = false;
        }
    }

    if(flag){
        cout<<0<<endl;
        return;
    }

    if(n == 1){
        cout<<1<<endl;
        return;
    }

    int cnt = 0;

    while (1)
    {
        if(allEmementZero(a)){
            break;
        }

        int mn = 1e18;

        for(int &x: a){
            if(x > 0 && x < mn){
                mn = x;
            }
        }

        bool flag1 = false;

        for(int &x: a){
            if(x == 0){
                x+= mn;
                flag1 = true;
            }
        }

        if(flag1){
            cnt++;
        }

        for(int &x: a){
            x-= mn;
        }

        cnt++;
        
        
    }

    // for(auto it: a){
    //     cout<<it<<" ";
    // }

    // cout<<endl;

    cout<<cnt<<endl;

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