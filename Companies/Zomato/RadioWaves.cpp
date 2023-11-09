#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int res = INT_MIN;

int f(int node, vector<int> &vis, vector<int> adj[], vector<int> &freq){
    vis[node] = 1;

    int largest = 0;
    int sec_largest = 0;

    for(auto child: adj[node]){
        if(!vis[child]){

            int childLength = f(child, vis, adj, freq);

            if(abs(freq[child]-freq[node]) > 1){
                continue;
            }

            if(childLength > sec_largest){
                sec_largest = childLength;

                if(sec_largest> largest){
                    swap(sec_largest, largest);
                }
            }
            
        }
    }

    int converge = 1 + largest + sec_largest;
    int p1 = 1;
    int p2 = 1 + max(largest, sec_largest);

    res = max({res, converge, p1, p2});
    return max({p1, p2});
}

int solve(vector<int> adj[], vector<int> &freq) {

    res = INT_MIN;
    int n = freq.size();
    vector<int> vis (n+1, 0);

    f(1, vis, adj, freq);

    return res;
}

void solve(){
    int n;
    cin>>n;

    vector<int> from(n-1);
    vector<int> to (n-1);

    for(int i = 0; i<n-1; i++){
        cin>>from[i];
    }

    for(int i = 0; i<n-1; i++){
        cin>>to[i];
    }


    vector<int> freq(n+1);
    for(int i = 1; i<=n; i++){
        cin>>freq[i];
    }

    vector<int> adj[n+1];

    for(int i = 0; i<n-1; i++){
        int u, v;
        u = from[i];
        v = to[i];
         
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<solve(adj, freq) -1<<endl;
    
}


signed main(){
    
    solve();

}