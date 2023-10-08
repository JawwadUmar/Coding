#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
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


int f(int mid, vector<int> &pref, vector<int> &suff, int req){

    vector<int> tempSuf = suff;
    reverse(tempSuf.begin(), tempSuf.end());

    int cnt1 = 0;

    for(int i = 0; i<=mid; i++){

        int left = i-1>=0 ? pref[i-1] : 0;
        int right = mid-i-1>=0 ?  tempSuf[mid-i-1] : 0;

        cnt1 = max(cnt1, left+right);
    }

    if(cnt1>= req){
        return true;
    }

    return false;

}


void solve(){

    int n, k;
    cin>>n>>k;

    int sum = 0;

    vector<int> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];

        sum+=a[i];
    }

    if(sum < k){
        cout<<-1<<endl;
        return;
    }

    if(sum == k){
        cout<<0<<endl;
        return;
    }

    if(k ==0){
        cout<<sum<<endl;
        return;
    }

    vector<int> pref(n, 0);
    vector<int> suff(n, 0);

    pref[0] = a[0];
    suff[n-1] = a[n-1];

    for(int i = 1; i<n; i++){
        pref[i] = pref[i-1] + a[i];
    }

    for(int i = n-2; i>=0; i--){
        suff[i] = suff[i+1] + a[i];
    }

    int req = sum - k;

    int low = sum - k;
    int high = n;

    int res = -1;

    while (high>=low)
    {
        int mid = high - (high - low)/2;

        if(f(mid, pref, suff, req)){
            res = mid;
            high = mid-1;
        }

        else{
            low = mid+1;
        }
    }

    cout<<res<<endl;
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t;
    // t=1;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}