#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve(){
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    //Kadane's Algorithm for mx subarray sum
    int res = INT_MIN;
    int curr = INT_MIN;

    for(int i = 0; i<n; i++){
        if(a[i] > curr + a[i]){
            curr = a[i];
        }

        else{
            curr = curr+a[i];
        }

        res =max(res, curr);
    }

    cout<<res<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    solve();
}