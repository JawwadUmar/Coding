#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
#define endl '\n'

void solve(){

    int n;
    cin>>n;

    deque<int> a(n);
    int xr = 0;

    for(int i = 0; i<n; i++){
        cin>>a[i];
        xr = xr^a[i];
    }

    if(xr == 0){
        cout<<"YES"<<endl;
        return;
    }


    int cnt = 0;
    int temp = 0;
    int i = 0;

    while (i<n)
    {
        temp = temp^a[i];

        if(temp == xr){
            temp = 0;
            cnt++;
        }

        i++;
    }

    if(cnt>=3){
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