#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define endl '\n'



void solve(){

    int n, k;
    cin>>n>>k;

    ordered_set<int> os;

    for(int i = 1; i<=n; i++){
        os.insert(i);
    }

    vector<int> res;
    int i = k;
    while (!os.empty())
    {
        i = i%(os.size());
        while (i<os.size())
        {
            int x = *(os.find_by_order(i));
            res.push_back(x);
            os.erase(x);
            i = i+k;
        }
        
    }


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
    // cin>>t;
    while(t--){
       solve();
    }
    return 0;
}