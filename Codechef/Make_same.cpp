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

    string s1, s2, s3;
    cin>>s1>>s2>>s3;

    int cnt1 = 0;
    int cnt0 = 0;

    int cnt0s1 = 0;
    int cnt1s1 = 0;

    for(auto &it: s1){
        if(it == '0'){
            cnt0++;
            cnt0s1++;
        }

        else{
            cnt1++;
            cnt1s1++;;
        }
    }

    int cnt0s2 = 0;
    int cnt1s2 = 0;

    for(auto &it: s2){
        if(it == '0'){
            cnt0++;
            cnt0s2++;
        }

        else{
            cnt1++;
            cnt1s2++;
        }
    }

    int cnt0s3 = 0;
    int cnt1s3 = 0;

    for(auto &it: s3){
        if(it == '0'){
            cnt0++;
            cnt0s3++;
            
        }

        else{
            cnt1++;
            cnt1s3++;
        }
    }

    if(cnt1%n != 0 || cnt0%n != 0){
        cout<<-1<<endl;
        return;
    }

    if(cnt1 == 3*n || cnt0 == 3*n){
        cout<<0<<endl;
        return;
    }

    if(cnt0 < cnt1){

        int mx = max({cnt0s1, cnt0s2, cnt0s3});
        cout<< n -mx <<endl;
        return;
    }

    else{

        int mx = max({cnt1s1, cnt1s2, cnt1s3});
        cout<<n-mx<<endl;
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