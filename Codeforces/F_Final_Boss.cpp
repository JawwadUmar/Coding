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


bool isPossible(int mid, int h, vector<int> &a, vector<int> &c){
    int x = 0;
    int n = a.size();

    for(int i = 0; i<n; i++){
        int no_of_turns = (mid-1)/c[i] + 1;
        if(no_of_turns>= h || a[i] >=h){
            return true;
        }

        x+= a[i]*no_of_turns;

        if(x>=h){
            return true;
        }
    }

    return false;
}

void solve(){

    int h, n;
    cin>>h>>n;
    vector<int> a(n);
    vector<int> c(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    for(int i = 0; i<n; i++){
        cin>>c[i];
    }

    int high = 1e18;
    int low = 1;
    int res = 69;

    while (high>=low)
    {
        int mid = high - (high-low)/2;

        if(isPossible(mid, h, a, c)){
            res = mid;
            high = mid-1;
        }

        else{
            low = mid+1;
        }
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