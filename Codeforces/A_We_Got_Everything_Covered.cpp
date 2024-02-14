#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){

    int n, k;
    cin>>n>>k;

    string a = "";

    for(char c = 'a'; c<'a'+k; c++){
        a+=c;
    }

    string res = a;

    while (n>1)
    {
        res+=a;
        n--;
    }

    cout<<res<<endl;
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