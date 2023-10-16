#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
void solve(){

    int n, m, k;
    cin>>n>>m>>k;

    vector<int> a(n);
    
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    vector<int> b(m);

    for(int i = 0; i<m; i++){
        cin>>b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0;
    int j = 0;

    int cnt = 0;

    while (i<n && j<m)
    {
        if(a[i] >= b[j]-k && a[i] <= b[j]+k){
            cnt++;
            i++;
            j++;
        }

        else if(a[i] < b[j] -k){
            i++;
        }

        else if(a[i] > b[j] + k){
            j++;
        }
    }

    cout<<cnt<<endl;
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t = 1;
    // cin>>t;
    while(t--){
       solve();
    }
    return 0;
}