#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
    vector<int> rank;
    vector<int> parent;
    vector<int> size;

    DisjointSet(int n){
        rank.resize(n+1, 0);
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

    void UnionByRank(int u, int v){
        int u_p_u = findUltimateParent(u);
        int u_p_v = findUltimateParent(v);

        if(rank[u_p_u] > rank[u_p_v]){
            parent[u_p_v] = u_p_u;
        }

        else if(rank[u_p_u] < rank[rank[u_p_v]]){
            parent[u_p_u] = u_p_v;
        }

        else{
            parent[u_p_u] = u_p_v;
            rank[u_p_u]++;
        }
    }

    void UnionBySize(int u, int v){
        int u_p_u = findUltimateParent(u);
        int u_p_v = findUltimateParent(v);

        if(size[u_p_u] > size[u_p_v]){
            parent[u_p_v] = u_p_u;
            size[u_p_v]++;
        }

        else{
            parent[u_p_u] = u_p_v;
            size[u_p_u]++;
        }
    }
};

int main(){
    DisjointSet ds(6);

    ds.UnionByRank(1, 2);
    ds.UnionByRank(2, 3);
    ds.UnionByRank(1, 3);
    ds.UnionByRank(4, 5);
    ds.UnionByRank(1, 6);
    ds.UnionByRank(5, 6);

    if(ds.findUltimateParent(4) == ds.findUltimateParent(1)){
        cout<<"YES"<<endl;
    }

    else{
        cout<<"NO"<<endl;
    }
}