#include <bits/stdc++.h>
using namespace std;

#define int long long 


void solve(){
    int a1, b1;
    cin>>a1>>b1;

    int a2, b2;
    cin>>a2>>b2;

    //Is it possible that, while Dima was not watching the game, the teams never had an equal score?

    if((a1< b1 && a2> b2 )|| (a1>b1 && a2< b2)){
        cout<<"NO"<<endl;
        return;
    }


    cout<<"YES"<<endl;
}

signed main(){
    int t;
    cin>>t;

    while (t--)
    {
        solve();
    }
    
}