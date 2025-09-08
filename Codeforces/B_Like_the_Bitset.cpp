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

    string s;
    cin>>s;

    vector<int> perm(n);
    int num = 1;

    for(int i = 0; i<s.size(); i++){
        if(s[i] == '1'){
            perm[i] = num;
            num++;
        }
    }


    for(int i = 0; i<s.size(); i++){
        if(s[i] == '0'){
            perm[i] = num;
            num++;
        }
    }

    //if there are k consecutive ones you can't do anything
    int cnt = 0;

    for(int i = 0; i<n; i++){
        if(s[i] == '1'){
            cnt++;

            if(cnt == k){
                cout<<"NO"<<endl;
                return;
            }
        }

        else{
            cnt = 0;
        }
    }

    // set<int, greater<int>> st;
    // int i = 0;
    // int j = 0;
    
    // while (i<n)
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


    cout<<"YES"<<endl;

    for(auto it: perm){
        cout<<it<<" ";
    }
    cout<<endl;


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