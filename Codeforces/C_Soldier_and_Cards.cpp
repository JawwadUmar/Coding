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


void solve(){

    int n;
    cin>>n;

    int k1;
    cin>>k1;

    deque<int> dq1;
    deque<int> dq2;

    for(int i = 0; i<k1; i++){
        int x;
        cin>>x;
        dq1.push_back(x);
    }
    
    int k2;
    cin>>k2;

    vector<int> a(k2);

    for(int i = 0; i<k2; i++){
        int x;
        cin>>x;
        dq2.push_back(x);
    }

    map<pair<deque<int>, deque<int>>, int> mp;
    mp[{dq1, dq2}] = 1;
    int cnt = 0;

    while (1)
    {
        int x1 =dq1.front();
        int x2 = dq2.front();

        dq1.pop_front();
        dq2.pop_front();

        if(x1> x2){
            dq1.push_back(x2);
            dq1.push_back(x1);
        }

        else{
            dq2.push_back(x1);
            dq2.push_back(x2);
        }

        cnt++;

        if(dq1.empty()){
            cout<<cnt<<" 2"<<endl;
            return;
        }

        if(dq2.empty()){
            cout<<cnt<<" 1"<<endl;
            return;
        }

        if(mp.find({dq1, dq2}) != mp.end()){
            cout<<-1<<endl;
            return;
        }

        mp[{dq1, dq2}] = 1;
    }
    
    
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