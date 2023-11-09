#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
#define endl '\n'

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

    vector<int> a(n);
    map<int, int> mp;

    for(int i = 0; i<n; i++){
        cin>>a[i];
        mp[a[i]]++;
    }

    if(mp.size() == 1){
        cout<<-1<<endl;
        return;
    }

    int cnt = 0;
    int a1 = -1;
    int a2 = -1;

    for(auto it: mp){
        if(it.second > 1){
            if(a1 == -1){
                a1 = it.first;
            }

            else{
                a2 = it.first;
            }

            cnt++;
        }

        if(cnt == 2){
            break;
        }
    }

    if(cnt < 2){
        cout<<-1<<endl;
        return;
    }

    //1//1
    //2//3

    vector<int> b(n, -1);
    bool a1done = false;
    bool a2done = false;

    for(int i = 0; i<n; i++){
        if(a[i] == a1){
            if(a1done == false){
                a1done = true;
                b[i] = 1;
            }

            else{
                b[i] = 2;
            }
        }

        else if(a[i] == a2){
            if(a2done == false){
                a2done = true;
                b[i] = 2;
            }

            else{
                b[i] = 3;
            }
        }

        else{
            b[i] = 3;
        }
    }

    for(int i =0; i<n; i++){
        cout<<b[i]<<" ";
    }

    cout<<endl;
    

    


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