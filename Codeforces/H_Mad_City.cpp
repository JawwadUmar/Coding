#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long


bool dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int &enterA){
    vis[node] = 1;

    for(auto it: adj[node]){
        if(!vis[it]){
            if(dfs(it, node, vis, adj, enterA)){
                return true;
            }
        }

        else if(it != parent){
            enterA = it;
            return true;
        }
    }

    return false;
}


void solve(){
    int n;
    cin>>n;

    int a, b;
    cin>>a>>b;

    vector<vector<int>> edges;
    vector<int> adj[n+1];
    vector<int> vis(n+1, 0);

    for(int i = 0; i<n; i++){
        int u, v;
        cin>>u>>v;
        edges.push_back({u, v});

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(a == b){
        cout<<"NO"<<endl;
        return;
    }

    if(n == 3){
        cout<<"YES"<<endl;
        return;
    }

    int enterB = -1;
    dfs(b, 0, vis, adj, enterB);
    // cout<<enterB<<endl;

    if(enterB == b){
        cout<<"YES"<<endl;
        return;
    }

    if(enterB == a){
        cout<<"NO"<<endl;
        return;
    }


    fill(vis.begin(), vis.end(), 0);

    //check if a can reach enterB first
    queue<pair<int, int>> q;

    q.push({a, 0});
    vis[a] = 1;
    int d1 = INT_MAX;

    while (!q.empty())
    {
        int node = q.front().first;
        int d = q.front().second;
        q.pop();

        for(auto it: adj[node]){
            if(!vis[it]){
                q.push({it, d+1});
                vis[it] = 1;

                if(it == enterB){
                    d1 = d+1;
                    break;
                }
            }
        }
    }

    while (!q.empty())
    {
        q.pop();
    }

    fill(vis.begin(), vis.end(), 0);

    q.push({b, 0});
    vis[b] = 1;
    int d2 = INT_MAX;

    while (!q.empty())
    {
        int node = q.front().first;
        int d = q.front().second;
        q.pop();

        for(auto it: adj[node]){
            if(!vis[it]){
                q.push({it, d+1});
                vis[it] = 1;

                if(it == enterB){
                    d2 = d+1;
                    break;
                }
            }
        }
    }

    if(d1<= d2){
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    
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