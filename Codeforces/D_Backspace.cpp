#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve(){

    string s, t;
    cin>>s;
    cin>>t;

    int n = s.size();
    int m = t.size();

    string s1 = "";
    string s2 = "";
    string s3 = "";

    for(int i = 0; i<n; i+= 3){
        s1+= s[i];

        if(i+1 < n){
            s2+= s[i+1];
        }

        if(i+2 < n){
            s3+= s[i+2];
        }
    }

    if(s.find(t) == -1){
        cout<<"NO"<<endl;
        return;
    }

    if(s1.find(t) != -1 || s2.find(t) != -1 || s3.find(t) != -1){
        cout<<"YES"<<endl;
        return;
    }



    
}


signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while (t--)
    {
        solve();
    }
    
}