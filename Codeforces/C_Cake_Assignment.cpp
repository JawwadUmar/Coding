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


vector<int> fun(int x2, int y2){
    //p2 se p1 pr jana h 

    vector<int> res;
    int temp = 121;
    
    while (temp--)
    {

        if(x2 == y2){
            break;
        }

        if(x2 > y2){
            x2 = x2 - y2;
            y2 = y2*2;
            res.push_back(2);
        }

        else{
            y2 = y2 - x2;
            x2 = x2*2;
            res.push_back(1);
        }
    }

    reverse(res.begin(), res.end());
    return res;
    
}

void solve(){
    int k, x;
    cin>>k>>x;

    int ch = (1ll<<k);
    int vn = ch;

    int ch_f = x;
    int vn_f = (ch+vn) - x;

    vector<int> res = fun(ch_f, vn_f);

    cout<<res.size()<<endl;

    for(auto it: res){
        cout<<it<<" ";
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