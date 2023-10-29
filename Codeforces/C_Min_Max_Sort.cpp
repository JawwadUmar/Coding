#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
#define endl '\n'


bool f(int mid, int n, map<int, int> &mp){
    // (k, n-(k-1))

    for(int i = mid+1; i<= n - (mid-1); i++){
        if(mp[i] > mp[i-1]){
            continue;
        }

        return false;
    }

    return true;
}


void solve(){

    int n;
    cin>>n;

    vector<int> a(n+1, 0);
    map<int, int> mp;

    for(int i = 1; i<=n; i++){
        cin>>a[i];
        mp[a[i]] = i;
    }

    
    //(1,n) sorted no need 
    //(2, n-1) sorted 1 operation
    //(3, n-2) sorted 2 operation
    //.... (k, n-(k-1)) sorted k-1 operation needed

    //smallest value of k for which (k, n-(k-1)) is sorted

    int res = -1;
    int low = 1;
    int high = n/2;

    while (high>=low)
    {
        int mid = (high+low)/2;

        if(f(mid, n, mp)){
            res = mid;
            high = mid-1;
        }

        else{
            low = mid+1;
        }
    }

    if(res ==-1){
        cout<<n/2<<endl;
    }

    else{
        cout<<res-1<<endl;
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