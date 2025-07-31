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
    int n, s;
    cin>>n>>s;

    vector<int> a(n);
    int sum = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];

        if(a[i] == 1){
            cnt1++;
        }

        else if(a[i] ==2){
            cnt2++;
        }

        else{
            cnt3++;
        }

        sum+=a[i];
    }

    //1 2 0
    vector<int> v;

    while (cnt1--)
    {
        v.push_back(1);
    }

    
    while (cnt2--)
    {
        v.push_back(2);
    }

    while (cnt3--)
    {
        v.push_back(0);
    }
    


    if(s<sum || s == sum+1){
        for(auto it: v){
            cout<<it<<" ";
        }
        cout<<endl;

        return;
    }

    cout<<-1<<endl;

    


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