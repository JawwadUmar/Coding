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

int computeFarRight(char l, char r, int far_right, map<char, set<int>> &mp){
     int temp = far_right;

    for(char c = l; c<=r; c++){

        auto it = mp[c].upper_bound(far_right);

        if(it == mp[c].end()){
            return far_right;
        }

        else if(it!= mp[c].end()){
            temp = max(temp, *it);
        }
    }

    return temp;
}

void solve(){
    string s;
    cin>>s;
    int n = s.size();

    int m;
    cin>>m;

    string l, r;
    cin>>l>>r;

    map<char, set<int>> mp;

    for(int i = 0; i<n; i++){
        
        mp[s[i]].insert(i);
    }

    int far_right = computeFarRight(l[0], r[0], -1, mp);
    // cout<<far_right<<endl;
    
    for(int i = 1; i<m; i++){
        char left =  l[i];
        char right = r[i];

        int temp = computeFarRight(left, right, far_right, mp);
        // cout<<temp<<endl;

        if(temp == far_right){
            cout<<"YES"<<endl;
            return;
        }

        far_right = temp;
    }

    if(far_right == -1){
        cout<<"YES"<<endl;
        return;
    }

    else if(far_right >= n){
        cout<<"YES"<<endl;
    }

    cout<<"NO"<<endl;
    return;
    

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