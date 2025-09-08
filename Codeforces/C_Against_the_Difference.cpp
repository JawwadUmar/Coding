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


void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    vector<int> countUptoidx(n + 2);
    vector<int> dp(n + 2);

    map<int, vector<int>> mp;

    // 1 indexed array 

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
        countUptoidx[i] = mp[a[i]].size(); //how much a[i] has come up to i
    }

    // DP calculation
    for (int i = 1; i <= n; i++) {
        if (countUptoidx[i] >= a[i]) {

            // {
    //     while (st.size() > k-1)
    //     {
    //         st.erase(perm[j]);
    //         j++;
    //     }

    //     if(!st.empty() && s[i] == '1' && perm[i] > *st.begin()){
    //         cout<<"NO"<<endl;
    //         return;
    //     }
        
    //     st.insert(perm[i]);
    //     i++;
    // }
            int gp = countUptoidx[i] - a[i]; // starting index
            dp[i] = max(dp[mp[a[i]][gp] - 1] + a[i], dp[i - 1]);
        } else {

            // {
    //     while (st.size() > k-1)
    //     {
    //         st.erase(perm[j]);
    //         j++;
    //     }

    //     if(!st.empty() && s[i] == '1' && perm[i] > *st.begin()){
    //         cout<<"NO"<<endl;
    //         return;
    //     }
        
    //     st.insert(perm[i]);
    //     i++;
    // }
            dp[i] = dp[i - 1];
        }
    }

    //  ios_base::sync_with_stdio(0);
    // cout.tie(0);
    // cin.tie(0);
    
    // int t = 1;
    // cin>>t;

    cout << dp[n] << "\n";
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