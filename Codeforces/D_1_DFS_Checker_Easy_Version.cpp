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

bool dfs(int node, int idx, int n,  vector<int> &perm){
   
    if(idx >= perm.size() || node >perm.size()){
        return true;
    }

    if(perm[idx] != node){
        return false;
    }

    int c1 = 2*node;
    int c2 = 2*node+1;

    bool flag1 = dfs(2*node, idx+1, n/2, perm);
    bool flag2 = dfs(2*node+1, idx+n/2+1, n/2, perm);

    bool FLAG1 = flag1&flag2;

    flag1 = dfs(2*node+1, idx+1, n/2, perm);
    flag2 = dfs(2*node, idx+n/2+1, n/2, perm);

    bool FLAG2 = flag1&flag2;

    return FLAG1 | FLAG2;
}


void solve(){

    int n, q;
    cin>>n>>q;

    vector<int> parent(n-1);

    for(int i = 0; i<n-1; i++){
        cin>>parent[i];
    }

    vector<int> perm(n);
    for(int i = 0; i<n; i++){
        cin>>perm[i];
    }

    set<pair<int, int>> st;

    bool temp = dfs(1, 0, n, perm);

    for(int i = 0; i<q; i++){
        int x, y;
        cin>>x>>y;

        if(x>y){
            swap(x, y);
        }
        x--;
        y--;
        
        swap(perm[x], perm[y]);

        if(st.find({x, y}) != st.end()){
            st.erase({x, y});
        }

        else{
            st.insert({x, y});
        }

        if(st.empty()){
            if(temp){
                cout<<"YES"<<endl;
            }

            else{
                cout<<"NO"<<endl;
            }
        }

        else if(dfs(1, 0, n, perm)){
            cout<<"YES"<<endl;
        }

        else{
            cout<<"NO"<<endl;
        }
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