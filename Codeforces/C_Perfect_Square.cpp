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

string row1(int idx, vector<string> &v){
    

    int n = v.size();

    string res = "";

    for(int c = idx; c<=n-idx-1; c++){
        res+= v[idx][c];
    }

    return res;
}

string col1(int idx, vector<string> &v){
    
    int n = v.size();

    string res = "";

    for(int r = idx; r<=n-idx-1; r++){
        res+= v[r][idx];
    }

    reverse(res.begin(),res.end());
    return res;
}

string row2(int idx, vector<string> &v){

    int n = v.size();

    string res = "";

    for(int c = idx; c<=n-idx-1; c++){
        res+= v[n-idx-1][c];
    }

    reverse(res.begin(),res.end());
    return res;
}

string col2(int idx, vector<string> &v){
    
    int n = v.size();

    string res = "";

    for(int r = idx; r<=n-idx-1; r++){
        res+= v[r][n-idx-1];
    }

    // reverse(res.begin(),res.end());
    return res;
}

int minoperations(string &s1, string &s2, string &s3, string &s4){

    int res = 0;
    int four = 0;
    int n = s1.size();

    for(int i = 0; i<n; i++){

        char mx = max({s1[i], s2[i], s3[i], s4[i]});

        res+= mx-s1[i];
        res+= mx-s2[i];
        res+= mx-s3[i];
        res+= mx-s4[i];

        if(i==0){
            four+= mx-s1[i];
            four+= mx-s2[i];
            four+= mx-s3[i];
            four+= mx-s4[i];
        }

    }

    return res - four;
}

void solve(){

    int n;
    cin>>n;

    vector<string> v;

    for(int i = 0; i<n; i++){
        string s;
        cin>>s;

        v.push_back(s);
    }

    int i = 0;
    int res = 0;

    while (i<n/2)
    {

        string s1 = row1(i, v);
        string s2 = col1(i, v);
        string s3 = col2(i, v);
        string s4 = row2(i, v);
        
        res+= minoperations(s1, s2, s3, s4);

        i++;
    }

    // for(int i = 0; i<n/2; i++){
    //     string s1 = row1(i, v);
    //     string s2 = col1(i, v);
    //     string s3 = col2(i, v);
    //     string s4 = row2(i, v);

    //     cout<<s1<<endl;
    //     cout<<s2<<endl;
    //     cout<<s3<<endl;
    //     cout<<s4<<endl;

    //     cout<<endl;
        
    // }


    cout<<res<<endl;
    


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