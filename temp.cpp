#include <bits/stdc++.h>
using namespace std;

int solve(int N, int R, int M, vector<vector<int>> edges, int Q,
          vector<vector<int>> queries) {
    vector<vector<pair<int,int>>> g(N+1);
    vector<long long> edgeWeight(M+1);
    vector<int> edgeToNode(M+1);

    for (int i=0; i<M; i++) {
        int u=edges[i][0], v=edges[i][1], w=edges[i][2];
        g[u].push_back({v,i+1});
        g[v].push_back({u,i+1});
        edgeWeight[i+1]=w;
    }

    vector<int> parent(N+1), depth(N+1), heavy(N+1,0), head(N+1), pos(N+1);
    int curPos=0;

    function<int(int,int)> dfs = [&](int u,int p){
        int size=1, maxSub=0;
        for (auto [v,id]: g[u]) {
            if (v==p) continue;
            parent[v]=u;
            depth[v]=depth[u]+1;
            edgeToNode[id]=v;
            int sub=dfs(v,u);
            if (sub>maxSub) heavy[u]=v, maxSub=sub;
            size+=sub;
        }
        return size;
    };
    dfs(R,0);

    function<void(int,int)> decompose = [&](int u,int h){
        head[u]=h;
        pos[u]=++curPos;
        if (heavy[u]) decompose(heavy[u],h);
        for (auto [v,id]: g[u]) {
            if (v!=parent[u] && v!=heavy[u]) decompose(v,v);
        }
    };
    decompose(R,R);

    struct SegTree {
        int n; vector<long long> seg;
        void init(int n_){ n=n_; seg.assign(4*n,0); }
        void build(vector<long long>&arr,int idx,int l,int r){
            if(l==r){ seg[idx]=arr[l]; return; }
            int mid=(l+r)/2;
            build(arr,idx*2,l,mid);
            build(arr,idx*2+1,mid+1,r);
            seg[idx]=seg[idx*2]+seg[idx*2+1];
        }
        void update(int idx,int l,int r,int pos,long long val){
            if(l==r){ seg[idx]=val; return; }
            int mid=(l+r)/2;
            if(pos<=mid) update(idx*2,l,mid,pos,val);
            else update(idx*2+1,mid+1,r,pos,val);
            seg[idx]=seg[idx*2]+seg[idx*2+1];
        }
        long long query(int idx,int l,int r,int ql,int qr){
            if(qr<l||ql>r) return 0;
            if(ql<=l && r<=qr) return seg[idx];
            int mid=(l+r)/2;
            return query(idx*2,l,mid,ql,qr)+query(idx*2+1,mid+1,r,ql,qr);
        }
    } st;

    vector<long long> base(N+1,0);
    for (int i=1;i<=M;i++){
        int node=edgeToNode[i];
        base[pos[node]]=edgeWeight[i];
    }
    st.init(N);
    st.build(base,1,1,N);

    function<long long(int,int)> queryPath = [&](int u,int v){
        long long res=0;
        while (head[u]!=head[v]){
            if (depth[head[u]]<depth[head[v]]) swap(u,v);
            res+=st.query(1,1,N,pos[head[u]],pos[u]);
            u=parent[head[u]];
        }
        if (depth[u]>depth[v]) swap(u,v);
        res+=st.query(1,1,N,pos[u]+1,pos[v]);
        return res;
    };

    long long ans=0;
    for (int i=0;i<Q;i++){
        int type=queries[i][0];
        if (type==1){
            int u=queries[i][1], v=queries[i][2];
            ans+=queryPath(u,v);
        } else {
            int id=queries[i][1], w=queries[i][2];
            edgeWeight[id]=w;
            int node=edgeToNode[id];
            st.update(1,1,N,pos[node],w);
        }
    }
    return (int)ans;
}

int main(){
    vector<vector<int>> edges = {{1, 2, 5}};
    vector<vector<int>> queries = {{1, 2, 1}, {2,1, 2, 2}, {1, 1, 2}};
    cout<<solve(2, 1, 1, edges, 3, queries);
}