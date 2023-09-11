#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using mpi = map<int,int>;
using mps = map<int,set<int>>;


#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define endl '\n'
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fora(i, a, n) for(ll i = a; i < n; i++)
#define forni(i, n, v) for(ll i = 0; i < n; i++) cin>>v[i];
#define readi(e) int e; cin >> e;
#define readl(e) ll e; cin >> e;
#define reads(e) string e; cin >> e;
#define T int tt; cin >> tt; while(tt--)
#define C(e) {cout<<e<<endl; return 0;}
#define yes {cout<<"YES"<<endl; return 0;}
#define no {cout<<"NO"<<endl; return 0;}
#define r {cout<<"running"<<endl;}
#define re(e) cout<<e<<" ";

const unsigned int MOD = 1000000007;

bool static cmp(pair<int,int> &a,pair<int,int> &b)
{
    return a.first<b.first;
}


int solve()
{
    readl(n);
    reads(s);
    string ans;

    for(int i=0;i<=n;i++){
        ans.push_back('0');
    }

    int count_dist=0;

    for(ll i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1]) count_dist++;
    }

    if(count_dist==0){
        for(int i=0;i<=n;i++){
            ans.push_back('1');
        }
    }

    if(n%2==0){
        
        for(int i=count_dist;i<=n-count_dist;i+=2){
            ans[i] = '1';
        }    
    }
    else{
        for(int i=count_dist;i<=n-count_dist;i++){
            ans[i] = '1';
        }
    }
    
    for(int i=0;i<=n;i++) cout<<ans[i];   
    
    cout<<endl;
    return 0;
   
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    T
    {
        solve();
    }

    return 0;

}
