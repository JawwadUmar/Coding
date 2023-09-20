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


void solve(){
    
    int n;
    cin>>n;
    int sum = 0;

    vector<int> a(n);

    for(int i= 0; i<n; i++){
        cin>>a[i];
        sum+= a[i];
    }

    if(sum%n != 0){
        cout<<"No"<<endl;
        return;
    }

    int req = sum/n;
    map<int, pair<int, int>> solt;

    for(int i = 0; i<63; i++){
        int x = 1<<i; 
        for(int j = i+1; j<63; j++){
            int y = 1<<j;
            
            int diff = y -x;

            solt[diff]= {y, x};
        }
    }

    solt[0] = {0, 0};

    multiset<int> temp1;
    multiset<int> temp2;



    for(int i =0; i<n; i++){
        int diff = req - a[i];

        if(solt.find(diff) == solt.end()){
            cout<<"No"<<endl;
            return;
        }

        if(diff>= 0){
            temp1.insert(solt[diff].first);
            temp2.insert(solt[diff].second);
        }

        else if(diff<0){
            temp1.insert(solt[abs(diff)].second);
            temp2.insert(solt[abs(diff)].first);
        }

    }

    if(temp1 != temp2){
        cout<<"No"<<endl;
        return;
    }

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