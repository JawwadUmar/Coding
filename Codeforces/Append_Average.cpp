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


int findMinWeight(vector<int> weights, int d){
    multiset<int, greater<int>> m (weights.begin(), weights.end());
    int cnt = 0;
    int totalSum = 0;

    for(auto it: weights){
        totalSum+= it;
    }

    while(d--){
        auto it= m.begin();
        int x = *it;
        m.erase(it);
        int y = x/2;
        cnt+= y;
        m.insert(x-y);
    }

    return totalSum - cnt;
}

int getMinTime(int n, vector<int> hp, int nt, int priority_time){
    
    int res = 0;
    res+= priority_time * hp.size();
    sort(hp.begin(), hp.end());

    int x = hp.size()+1;
    if(hp[0] == 1){
        x--;
    }

    if(hp.back() == n){
        x--;
    }

    res+= x*nt;
    return res; 

}

void solve(){

    vector<int> hp = {1,4};
    cout<<getMinTime(4, hp, 1, 5);


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