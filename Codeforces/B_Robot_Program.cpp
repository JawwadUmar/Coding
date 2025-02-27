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

    int n, x, k;
    cin>>n>>x>>k;

    string s;
    cin>>s;
    
    int delx = 0;
    
    bool flag = false;
    int cnt = 0;

    for(int i = 0; i<n; i++){
        if(s[i] =='L'){
            delx--;
        }

        else{
            delx++;
        }

        cnt++;

        if(x+delx == 0){
            flag = true;
            break;
        }
    }

    if(flag == false){
        cout<<0<<endl;
        return;
    }

    else if(k < cnt){
        cout<<0<<endl;
        return;
    }

    else if(k == cnt){
        cout<<1<<endl;
        return;
    }

    k = k-cnt;
    int zeroDisplacementTime = -1;
    cnt = 0;
    delx = 0;


    for(int i = 0; i<n; i++){
        if(s[i] =='L'){
            delx--;
        }

        else{
            delx++;
        }

        cnt++;

        if(delx == 0 && zeroDisplacementTime ==-1){
            zeroDisplacementTime = cnt;
            break;
        }
    }

    if(zeroDisplacementTime == -1){
        cout<<1<<endl;
        return;
    }

    cout<<k/zeroDisplacementTime + 1<<endl;
    
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