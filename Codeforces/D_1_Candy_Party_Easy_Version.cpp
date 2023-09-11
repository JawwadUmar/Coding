#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
int binaryExponentiation(int x, int p){\
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

int numberOfSetBits(int n){
    return __builtin_popcount(n);
}

bool canBeObtained(int target) {
    vector<int> powersOf2;
    int power = 0;
    
    // Generate a list of powers of 2
    while ((1 << power) <= target) {
        powersOf2.push_back(1 << power);
        power++;
    }
    
    int n = powersOf2.size();
    
    // Try all possible combinations of powers of 2
    for (int mask = 1; mask < (1 << n); mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += powersOf2[i];
            }
        }
        
        if (sum == target) {
            return true;
        }
    }
    
    return false;
}


void solve(){
    int n;
    cin>>n;

    vector<int> a(n);
    int sum = 0;

    for(int i = 0; i<n; i++){
        cin>>a[i];
        sum+= a[i];
    }

    if(sum%n != 0){
        cout<<"No"<<endl;
        return;
    }

    vector<int> res(n);

    for(int i = 0; i<n; i++){
        res[i] = sum/n;
    }

    vector<int> diff(n);
    map<int, int> mp;

    for(int i = 0; i<n; i++){
        diff[i] = res[i] - a[i];

        if(!canBeObtained(abs(diff[i]))){
            cout<<"No 3"<<endl;
            return;
        }
        mp[diff[i]]++;
    }

    for(int i = 0; i<n; i++){
        if(mp[diff[i]] != mp[-diff[i]]){
            cout<<"No"<<endl;
            return;
        }
    }

    // for(auto it: diff){
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    cout<<"Yes"<<endl;

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