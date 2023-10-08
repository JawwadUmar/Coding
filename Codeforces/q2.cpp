#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    vector<int> parent;
    vector<int> rank;

    public:
        UnionFind(int n) {

        parent.resize(n + 1);
        
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        rank.resize(n + 1, 0);
    }

    int find(int x) {
        return (x == parent[x]) ? x : find(parent[x]);
    }

    void Union(int x, int y) {
        
        int px = find(x);
        int py = find(y);
        
        if (px == py) { 
            return;
        }
        
        if (rank[px] >= rank[py]) {
            parent[py] = px;
            rank[px] += rank[py];
        } 
        else {
            parent[px] = py;
            rank[py] += rank[px];
        }
    }
};

class node
{
    public:
    int node1;
    int node2;
    int cost;

    node(int n1, int n2, int c)
    {
        node1 = n1;
        node2 = n2;
        cost = c;
    }
};

static bool comp(node n1 , node n2)
{
    return n1.cost < n2.cost;
}

int supplyWater(int n, int k, vector<int> &wells, vector<vector<int>> &pipes) {
    
    //  Array/vector to hold the costs.
    vector<node> costs;
    
    for (int i = 1; i <= n; ++i) {
        node obj(0, i, wells[i - 1]);
        costs.push_back(obj);
    }

    for (int i = 0; i < k; ++i) {
        node obj(pipes[i][0], pipes[i][1], pipes[i][2]);
        costs.push_back(obj);
    }

    sort(costs.begin(), costs.end(), comp);

    int minCost = 0;

    UnionFind uf(n);
      
    for (auto edge : costs) {

        int rootX = uf.find(edge.node1);
        int rootY = uf.find(edge.node2);

        if (rootX == rootY){
            continue;
        }

        minCost += edge.cost;

        uf.Union(edge.node1, edge.node2);

        // For each union, we connnect one node.
        n--;

        // If all nodes already connected, terminate early.
        if (n == 0) {
            return minCost;
        }
    }
    
    return minCost;
}