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

int frequency(int idx, vector<int> &a){
    int first = a[idx];
    int cnt = 1;

    for(int j = idx+1; j<a.size(); j++){
        if(a[j] == first){
            cnt++;
        }
        else{
            break;
        }
    }

    return cnt;

}

void solve(){
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    if(a[0] != n){
        cout<<"NO"<<endl;
        return;
    }
    vector<int> res(n);
    reverse(a.begin(),a.end());
            int j=0;
            for(int i=0;i<n;i++){
                while(j < n && i+1 > a[j]){
                    j++;
                }
                res[i]=n-j;
            }


            reverse(a.begin(),a.end());
            for(int i=0;i<n;i++){
                if(a[i]!=res[i]){
                    cout<<"NO"<<endl;
                    return;
                }
            }
            cout<<"YES"<<endl;

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