#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
#define endl '\n'

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

    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    string s;
    cin>>s;

    int xr0 = 0;
    int xr1 = 0;

    for(int i = 0; i<n; i++){
        if(s[i] == '1'){
            xr1 = xr1^a[i];
        }

        else{
            xr0 = xr0^a[i];
        }
    }

    vector<int> pref(n, 0);
    vector<int> suff(n, 0);

    pref[0] = a[0];

    for(int i = 1; i<n; i++){
        pref[i] = a[i]^pref[i-1];
    }

    suff[n-1] = a[n-1];

    for(int i = n-2; i>=0; i--){
        suff[i] = a[i]^suff[i+1];
    }

    //l to r
    int total = pref[n-1];

    //total^pref[l-1]^suff[r+1]


    int q;
    cin>>q;

    while (q--)
    {
        int qtp;
        cin>>qtp;

        if(qtp ==1){
            int l, r;
            cin>>l>>r;

            l--;
            r--;
            
            int left = 0;
            int right = 0;

            if(l-1 >=0){
                left = pref[l-1];
            }

            if(r+1<= n-1){
                right = suff[r+1];
            }

            int xr_l_r = total^left^right;
            xr1 = xr1^xr_l_r;
            xr0 = xr0^xr_l_r;
        }

        else if(qtp == 2){
            int g;
            cin>>g;

            if(g == 1){
                cout<<xr1<<" ";
            }

            else{
                cout<<xr0<<" ";
            }
        }
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