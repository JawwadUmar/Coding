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
    int n, k, p, m;
    cin>>n>>k>>p>>m;
    int temp = k;
    multiset<int> st;
    queue<int> q;
    int cost_win_condition = -1;

    for(int i =0; i<n; i++){
        int x;
        cin>>x;
        if(temp > 0){
            st.insert(x);
            temp--;
        }
        else{
            q.push(x);
        }

        if(i == p-1){
            cost_win_condition = x;
        }
    }

    int cost = 0;
    int count = 0;

    while (cost + cost_win_condition <= m)
    {
        if(p <= k){
            cost+= cost_win_condition;
            count++;
            auto it = st.find(cost_win_condition);
            q.push(*it);
            st.erase(it);
            st.insert(q.front());
            q.pop();
            p = n;
        }

        else{
            auto it = st.begin();
            cost+= *it;
            q.push(*it);
            st.erase(it);
            st.insert(q.front());
            q.pop();
            p--;
        }
    }

    cout<<count<<endl;

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