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
    vector<int> b(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    for(int i = 0; i<n; i++){
        cin>>b[i];
    }

    int i1 = 0;
    int i2 = n-1;

    int j1 = 0;
    int j2 = n-1;

    while (1)
    {
        if(i1 == i2){
            cout<<"Bob"<<endl;
            return;
        }
        
        if((a[i1] != b[j1]) && (a[i1] != b[j2])){
            cout<<"Alice"<<endl;
            return;
        }

        if((a[i2] != b[j1]) && (a[i2] != b[j2])){
            cout<<"Alice"<<endl;
            return;
        }

        if(a[i1] == b[j1]){
            i1++;
            j1++;
        }

        else if(a[i1] == b[j2]){
            i1++;
            j2--;
        }

        else if(a[i2] == b[j1]){
            i2--;
            j1++;
        }

        else if(a[i2] == b[j2]){
            i2--;
            j2--;
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