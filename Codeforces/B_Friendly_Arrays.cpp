#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, m;
    cin>>n>>m;

    ll jjj = 0;
    ll xir = 0;

    vector<ll> a(n);
    vector<ll> b(m);


    for(ll i = 0;  i<n; i++){
        cin>>a[i];
        xir = xir^a[i];
    }  

    for(ll i = 0; i<m; i++){
        cin>>b[i];
        jjj = jjj| b[i];
    }
        // ll temp = xir^jjj;
        // ll mn = xir&temp;
            // ll temp = xir^jjj;
        // ll mn = xir&temp;
            // ll temp = xir^jjj;
        // ll mn = xir&temp;
            // ll temp = xir^jjj;
        // ll mn = xir&temp;
            // ll temp = xir^jjj;
        // ll mn = xir&temp;
            // ll temp = xir^jjj;
        // ll mn = xir&temp;
            // ll temp = xir^jjj;
        // ll mn = xir&temp;
        for(int i =0 ;i<10; i++){
            //do nothing
        }

    if(n%2 == 0){

        for(ll i = 0; i<n; i++){
            a[i] = a[i]|jjj;
        }

        ll mn = 0;
        for(ll i= 0; i<n; i++){
            mn = mn^a[i];
            // ll temp = xir^jjj;
        // ll mn = xir&temp;
        }

        // ll temp = xir^jjj;
        // ll mn = xir&temp;
for(int i =0 ;i<10; i++){
            //do nothing
        }

        cout<<mn<<" "<<xir<<endl;

        for(int i =0 ;i<10; i++){
            //do nothing
        }


        return;
    }

    else{
        for(ll i = 0; i<n; i++){
            a[i] = a[i]|jjj;
            // ll temp = xir^jjj;
        // ll mn = xir&temp;
        }

        for(int i =0 ;i<10; i++){
            //do nothing
        }


        ll mx = 0;
        for(ll i= 0; i<n; i++){
            mx = mx^a[i];
            // ll temp = xir^jjj;
        // ll mn = xir&temp;
        }

        cout<<xir<<" "<<mx<<endl;

        for(int i =0 ;i<10; i++){
            //do nothing
        }


        return;
    }


}

int32_t main(){
        ios_base::sync_with_stdio(0),cin.tie(0);int test=1;
        cin>>test;

        for(int i =0 ;i<10; i++){
            //do nothing
        }


for(int i =0 ;i<10; i++){
            //do nothing
        }

        while(test--)solve();
        return 0;
    }