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

vector<int> nearestMultiple(int y, int a){

    int rem = y%a;
    int ans1 = y - rem;
    int ans2 = ans1+ a;

    return {ans1, ans2};
}



void solve(){
    int a, x, y;
    cin>>a>>x>>y;

    //-a to a
    if(x<= -a || x>=a){
        cout<<-1<<endl;
        return;
    }

    if(y<0){
        cout<<-1<<endl;
        return;
    }

    int temp = abs(y);

    if(temp%a ==0){
        cout<<-1<<endl;
        return;
    }

    vector<int> v = nearestMultiple(abs(y), a);
    // cout<<v[0]<<" "<<v[1]<<endl;
    int level;

    if(v[0] ==0){

        double A = a;

        
        if(x>=( double)(A/2) || x<= -(double)(A/2)){
            cout<<-1<<endl;
            // cout<<"isme"<<endl;
            return;
        }

        else{
            cout<<1<<endl;
            // cout<<"hh1"<<endl;
            return;
        }
    }

    else if((v[0]/a)%2 == 1){
        double A = a;
        if(x>= (double)(A/2) || x<= -(double)(A/2)){
            cout<<-1<<endl;
            return;
        }

        else{
           
            level = v[1]/a;
        }
    }

    else if((v[0]/a)%2 == 0){

        if(x ==0){
            cout<<-1<<endl;
            return;
        }
        // cout<<v[1]/a<<endl;
        // // cout<<"hh3"<<endl;
        level = v[1]/a;
    }

    int ans = 2;
    for(int i = 2; i<level; i++){

        if(i%2 ==0){
            ans++;
        }

        else{
            ans+=2;
        }
    }

    // cout<<level<<endl;

    if(level %2 == 0){
        cout<<ans<<endl;
    }   

    else if(x > 0){
        // cout<<"really"<<endl;
        cout<<ans+1<<endl;
    }

    else{
        cout<<ans<<endl;
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t;
    t=1;
    // cin>>t;
    while(t--){
       solve();
    }
    return 0;
}