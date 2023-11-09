#include <bits/stdc++.h>
using namespace std;
#define int long long

int tsp(int node, int mask, vector<int> &k, vector<vector<int>> &indexToNodeDis, vector<vector<int>> &dp, int allVISITED){
    
    if(mask == allVISITED){
        return indexToNodeDis[node][0];
    }
    
    if(dp[node][mask] != -1){
        return dp[node][mask];
    }
    
    int n = k.size();
    int ans = 1e18;
    
    for(int i = 0; i<n; i++){
        
        int visited = ((1<<i)&(mask));
        if(visited ==0){
            int newans = indexToNodeDis[node][k[i]] + tsp(i, (mask|(1<<i)), k, indexToNodeDis, dp, allVISITED);
            ans = min(ans, newans);
        }
    }
    
    return dp[node][mask] = ans;
}


long getMinimumTime(int n, vector<int> f, vector<int> t, vector<int> w, vector<int> k){
	vector<pair<int,int>> adj[n+1];

	for(int i=0;i<f.size();i++){
	    adj[f[i]].push_back({t[i],w[i]}); //node, weight
	    adj[t[i]].push_back({f[i],w[i]});
	}

    k.push_back(0);

    vector<vector<int>> indexToNodeDis (k.size(), vector<int> (n+1, 1e18));

    //indexToNodeDis[i][j] ==> smallest dist b/w k[i] to jth node

    for(int i = 0; i<k.size(); i++){
        indexToNodeDis[i][k[i]] = 0;

        set<pair<int, int>> st;
        st.insert({0, k[i]});

        while (!st.empty())
        {
            auto pit = st.begin();
            int node = pit->second;
            int d = pit->first;
            st.erase(pit);

            for(auto it: adj[node]){
                int adjacentNode = it.first;
                int edgeWt = it.second;

                if(indexToNodeDis[i][adjacentNode] > d + edgeWt){
                    indexToNodeDis[i][adjacentNode] = d + edgeWt;
                    st.insert({d + edgeWt, adjacentNode});
                }
            }
        }  
    }

    int m = k.size();

    int allVISITED = (1<<m) -1;

    vector<vector<int>> dp(m+1, vector<int> (1<<m + 1, -1));
    int mask = 1<<(m-1);
    int ans = tsp(m-1, mask, k, indexToNodeDis, dp, allVISITED);

    return ans ==1e18 ? -1 : ans;

}

signed main(){

    int n = 5;
    // vector<int> f = {0, 1, 0};
    // vector<int> t = {1, 2, 2};
    // vector<int> w = {10, 20, 50};
    // vector<int> k = {1, 2};
    //expected: 60

    vector<int> f = {0, 0, 4, 4, 1, 1};
    vector<int> t = {1, 4, 1, 3, 2, 3};
    vector<int> w = {10, 3, 5, 4, 2, 4};
    vector<int> k = {1, 3};
    //expected: 19

    cout<<getMinimumTime(n, f, t, w, k)<<endl;

}