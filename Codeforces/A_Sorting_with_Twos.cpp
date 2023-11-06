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


bool isSorted(int st, int en, vector<int> a){

    int n = a.size();

    if(st + 1 >= n){
        return true;
    }

    en = min(n-1, en);

    vector<int> temp = a;

    sort(temp.begin() + st, temp.begin()+en+1);


    // for(auto it: temp){
    //     cout<<it<<" ";
    // }


    for(int i = st; i<=en; i++){
        if(a[i] != temp[i]){
            return false;
        }
    }

    return true;
}


void solve(){

    int n;
    cin>>n;

    vector<int> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    if(n<=3){
        cout<<"YES"<<endl;
        return;
    }

    if(a[2] > a[3]){
        cout<<"NO"<<endl;
        return;
    }

    if(n==5){
        cout<<"YES"<<endl;
        return;
    }

    // isSorted(4, 7, a);

    if(!isSorted(4, 7,a)){
        // cout<<"1"<<endl;
        cout<<"NO"<<endl;
        return;
    }

    if(!isSorted(8, 15, a)){
        //  cout<<"2"<<endl;
        cout<<"NO"<<endl;
        return;
    }

    if(!isSorted(16, 19, a)){
        //  cout<<"3"<<endl;
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;



    
    
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