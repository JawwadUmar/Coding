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


long long lcm(long long a, long long b){

    return (a*b)/(__gcd(a, b));
}


void solve(){
    long long a, b, c, m;
    cin>>a>>b>>c;
    cin>>m;

    long long lcm_ab = lcm(a,b);
    long long lcm_bc = lcm(b, c);
    long long lcm_ca = lcm(c, a);

    long long lcm_abc = lcm(lcm(a,b), c);

    long long days_shared = (m/lcm_abc);

    // cout<<days_shared<<endl;
    
    long long days_shared_ab = m/lcm_ab - days_shared;
    long long days_shared_bc = m/lcm_bc - days_shared;
    long long days_shared_ca = m/lcm_ca - days_shared;

    // cout<<days_shared_ab<<" "<<days_shared_bc<<" "<<days_shared_ca<<endl;

    long long days_a = m/a - days_shared_ab - days_shared_ca -days_shared;
    long long days_b = m/b - days_shared_ab - days_shared_bc -days_shared;
    long long days_c = m/c - days_shared_bc - days_shared_ca -days_shared;

    // cout<<days_a<<" "<<days_b<<" "<<days_c<<endl;

    long long val_a = days_a*6 + 3*(days_shared_ab+ days_shared_ca) + 2*(days_shared);
    long long val_b = days_b*6 + 3*(days_shared_ab+ days_shared_bc) + 2*(days_shared);
    long long val_c = days_c*6 + 3*(days_shared_bc +days_shared_ca) + 2*(days_shared);

    cout<<val_a<<" "<<val_b<<" "<<val_c<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    long long t = 1;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}