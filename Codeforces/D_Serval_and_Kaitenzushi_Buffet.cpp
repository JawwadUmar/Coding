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


int f(int idx, int r, int k, vector<int>& a, unordered_map<string, int>& memo) {
    int n = a.size();

    // Base case
    if (idx >= n) {
        if (r == 0) {
            return 0;
        }
        return -1e18;
    }

    // Create a unique key for the current state
    string key = to_string(idx) + "," + to_string(r);

    // Check if the result is already computed
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    // Recursive cases
    int take = a[idx] + f(idx + 1, r + k, k, a, memo);
    int not_take = f(idx + 1, r, k, a, memo);
    int eat = -1e18;

    if (r - 1 >= 0) {
        eat = f(idx + 1, r - 1, k, a, memo);
    }

    // Store the result in the memo table
    memo[key] = max({take, not_take, eat});

    return memo[key];
}

int main_function(int k, vector<int>& a) {
    unordered_map<string, int> memo;
    return f(0, 0, k, a, memo);
}


void solve(){

    int n, k;
    cin>>n>>k;

    vector<int> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    unordered_map<string, int> memo;
    cout<< f(0, 0, k, a, memo)<<endl;

    
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