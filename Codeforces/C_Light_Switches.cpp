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

    int n, k;
    cin>>n>>k;

    vector<int> a(n);
    int mx = 0;

    for(int i = 0; i<n; i++){
        cin>>a[i];
        mx = max(mx, a[i]);
    }

    vector<int> left, right;

    for(int i = 0; i<n; i++){
        int l = (a[i])%(2*k);
        int r = (a[i] + k -1)%(2*k);

        left.push_back(l);

        if(r <l){
            r+= 2*k;
        }

        right.push_back(r);
    }

    int x = left[0];
    int y = right[0];

    for(int i = 0; i<n; i++){
        cout<<left[i]<<" "<<right[i]<<endl;
    }

    for(int i = 1; i<n; i++){
        
        if(x> right[i] || y<left[i]){
            cout<<-1<<endl;
            return;
        }

        x = max(x, left[i]);
        y = min(y, right[i]);
    }

    //rem of x
    int temp_rem = mx%(2*k);
    int toadd = x - temp_rem;

    cout<<mx+toadd<<endl;


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