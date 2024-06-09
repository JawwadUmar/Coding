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

    string num = to_string(n);
    int carry = 0;
    string ans1 = "";
    string ans2 = "";
    map<int, pair<int, int>> mp;

    mp[0] = {5, 5};
    mp[1] = {5, 6};
    mp[2] = {6, 6};
    mp[3] = {6, 7};
    mp[4] = {7, 7};
    mp[5] = {7, 8};
    mp[6] = {8, 8};
    mp[7] = {8, 9};
    mp[8] = {9, 9};

    for(int i = num.size()-1; i>=1; i--){
        int digit = num[i] - '0';
        digit = digit - carry;

        if(digit<0){
            digit+=10;
        }

        if(mp.find(digit) == mp.end()){
            cout<<"NO"<<endl;
            return;
        }

        int d1 = mp[digit].first;
        int d2 = mp[digit].second;
        carry = (d1+d2)/10;

        ans1+= to_string(d1);
        ans2+= to_string(d2);
    }

    
    reverse(ans1.begin(), ans1.end());
    reverse(ans2.begin(), ans2.end());

    // cout<<ans1<<" "<<ans2<<endl;

    int num1 = stoll(ans1);
    int num2 = stoll(ans2);

    if(num1 + num2 == n){
        cout<<"YES"<<endl;
    }

    else{
        cout<<"NO"<<endl;
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