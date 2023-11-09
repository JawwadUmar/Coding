#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
#define endl '\n'

void undorotate(vector<int> &a, int x){

    int n = a.size();
    x = x%n;
    x = n-x;

    reverse(a.begin(), a.begin() + x);
    reverse(a.begin()+x, a.end());

    reverse(a.begin(), a.end());
}

void solve(){

    int n, k;
    cin>>n>>k;

    vector<int> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    k = min(k, n);

    int s = n-1;

    while (k--)
    {
        if(a[s] == n){
            cout<<"Yes"<<endl;
            return;
        }

        else if(a[s] > n){
            cout<<"No"<<endl;
            return;
        }

        s = s - a[s];

        if(s<0){
            s+= n;
        }
    }

    cout<<"Yes"<<endl;
    
    
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