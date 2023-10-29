#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

class DisjointSet{
    public:
    vector<int> parent;
    vector<int> size;

    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);

        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findUltimateParent(int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = findUltimateParent(parent[node]);
    }

    void UnionBySize(int u, int v){

        int u_p_u = findUltimateParent(u);
        int u_p_v = findUltimateParent(v);


        if(size[u_p_u] > size[u_p_v]){
            size[u_p_u]+=1;
            parent[u_p_v] = u_p_u;
        }

        else{
            size[u_p_v]+=1;
            parent[u_p_u] = u_p_v;
        }
    }

};


int MSTcost(vector<vector<int>>&edges, int n, vector<int> &powerStations, vector<pair<int, int>> &connections){

    DisjointSet ds(n);
    int res = 0;

    for(auto it: edges){
        int w = it[0];
        int u = it[1];
        int v = it[2];

        if(ds.findUltimateParent(u) != ds.findUltimateParent(v)){
            ds.UnionBySize(u, v);
            res+= w;

            if(u == 0 || v==0){
                powerStations.push_back(u+v);
                continue;
            }

            connections.push_back({u, v});
        }
    }

    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<pair<int,int>> v(n+1);

    for(int i = 1; i<=n; i++){
        int x, y;
        cin>>x>>y;

        v[i] = {x, y};
    }

    vector<int> cost(n+1);

    for(int i = 1; i<=n; i++){
        cin>>cost[i];
    }

    vector<int> pathCost(n+1);

    for(int i= 1; i<=n; i++){
        cin>>pathCost[i];
    }

    vector<vector<int>> edges;

    for(int i = 1; i<=n; i++){
        for(int j = i+1; j<=n; j++){

            int w = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
            w  = w * (pathCost[i] + pathCost[j]);
            edges.push_back({w, i, j});
        }
    }

    //let node 0 be the auxiliary node :)

    for(int i = 1; i<=n; i++){
        int w = cost[i];

        edges.push_back({w, i, 0});
    }

    sort(edges.begin(), edges.end());

    vector<int> powerStations;
    vector<pair<int, int>> connections;
    cout<<MSTcost(edges, n, powerStations, connections)<<endl;

    cout<<powerStations.size()<<endl;

    for(auto it: powerStations){
        cout<<it<<" ";
    }
    cout<<endl;

    cout<<connections.size()<<endl;

    for(auto it: connections){
        cout<<it.first<<" "<<it.second<<endl;
    }

}