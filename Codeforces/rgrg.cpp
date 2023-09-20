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

bool f(string &s){
    int x = 0;
    int y = 0;

    int dir = 1;
    int tempx = 0;
    int tempy = 0;

    for(int j = 0; j<4; j++){
        for(int i = 0; i<s.size(); i++){
        if(dir == 1){
            // cout<<"1"<<endl;
            if(s[i] == 'G'){
                tempx++;
            }
            if(s[i] == 'L'){
                dir = 4;
            }
            if(s[i] == 'R'){
                dir = 2;
            }
        }


        else if(dir == 2){
            // cout<<"2"<<endl;
            if(s[i] == 'G'){
                tempy--;
            }
            if(s[i] == 'L'){
                dir = 1;
            }
            if(s[i] == 'R'){
                dir = 3;
            }
        }

        else if(dir == 3){
            // cout<<"3"<<endl;;
            if(s[i] == 'G'){
                tempx--;
            }
            if(s[i] == 'L'){
                dir = 2;
            }
            if(s[i] == 'R'){
                dir = 4;
            }
        }

        else if(dir == 4){
            // cout<<"4"<<endl;
            if(s[i] == 'G'){
                tempy++;
            }
            if(s[i] == 'L'){
                dir = 3;
            }
            if(s[i] == 'R'){
                dir = 1;
            }
        }
    }
    }

    // cout<<tempx<<" "<<tempy<<endl;
    if(tempx == x && tempy == y){
        return true;
    }

    return false;
}


void solve(){
    vector<string> commands;
    vector<string> res;
    int n;
    cin>>n;

    for(int i= 0; i<n; i++){
        string s;
        cin>>s;

        commands.push_back(s);
    }

    for(int i = 0; i<n; i++){
        string s = commands[i];

        if(f(s)){
            res.push_back("YES");
        }

        else{
            res.push_back("NO");
        }
    }

    for(auto it: res){
        cout<<it<<endl;
    }

    
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