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

    vector<int> a(n+1);

    int l, r;
    l = r = -1;
    for(int i = 1; i<=n; i++){
        cin>>a[i];

        if(a[i] == 0){
            if(l == -1){
                l = i;
                r = i;
            }

            else{
                r = i;
            }
        }
    }


    if(l==1 && r == n){
        cout<<3<<endl;
        cout<<1<<" "<<(n+1)/2<<endl;
        cout<<2<<" "<<n - (n+1)/2 +1<<endl;
        cout<<1<<" "<<2<<endl;
    }

    else if(l == r && l == -1){
        cout<<1<<endl;
        cout<<1<<" "<<n<<endl;
    }

    else if(l == r){

        cout<<2<<endl;
        if(l==1){

            cout<<1<<" "<<2<<endl;
            cout<<1<<" "<<n-1<<endl;
        }

        else if(l==n){

            cout<<n-1<<" "<<n<<endl;
            cout<<1<<" "<<n-1<<endl;
        }

        else{
            cout<<l<<" "<<l+1<<endl;
            cout<<1<<" "<<n-1<<endl;
        }
    }

    else {

        cout<<2<<endl; 
        cout<<l<<" "<<r<<endl;
        int x = r-l+1;

        cout<<1<<" "<<n-x+1<<endl;
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