#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
#define endl '\n'

void solve(){

    int n;
    cin>>n;

    vector<int> a(n);

    int cnt1 = 0;
    int sum = 0;

    for(int i = 0; i<n; i++){
        cin>>a[i];

        if(a[i] ==1){
            cnt1++;
        }

        sum+= a[i];
    }

    int negcnt = n-cnt1;
    int res = 0;

    if(sum < 0){
        int dist = abs(sum);

         res= (dist+1)/2;
        negcnt-= res;

    }

    if(negcnt%2 ==0){
        cout<<res<<endl;
    }

    else{
        cout<<res+1<<endl;
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