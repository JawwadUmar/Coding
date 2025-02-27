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

int findx(vector<int> &b, int y){
    //smallest value of x<=y

    int low = 0;
    int high = b.size()-1;
    int x = -1;

    while (high>= low)
    {
        int mid = (low+high)/2;

        if(b[mid] <= y){
            x = mid;
            high = mid-1;
        }

        else{
            low = mid+1;
        }
    }

    return x;
}


void solve(){

    int n;
    cin>>n;
    int m;
    cin>>m;

    vector<int> a(n);
    for(int i =0; i<n; i++){
        cin>>a[i];
    }

    vector<int> b(m);

    for(int i = 0; i<m; i++){
        cin>>b[i];
    }

    sort(b.begin(), b.end());

    for(int i = 0; i<n-1; i++){
        if(a[i] > a[i+1]){
            int x = findx(b, a[i+1] + a[i]);

            if(x == -1){
                cout<<"NO"<<endl;
                return;
            }

            a[i] =  b[x] - a[i];
        }
    }


    for(int i = 1; i<n; i++){
        if(a[i] < a[i-1]){
            cout<<"NO"<<endl;
            return;
        }
    }

     cout<<"YES"<<endl;

    
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