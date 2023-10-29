#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main(){

    int n;
    cin>>n;

    vector<vector<int>> adjMat (n+1, vector<int> (n+1, 0));

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin>>adjMat[i][j];
        }
    }

    vector<int> deleteVertices(n+1);

    for(int i = 1; i<=n; i++){
        cin>>deleteVertices[i];
    }

    int idx = n;

    vector<vector<int>> dist = adjMat;

    vector<int> res;

    while (idx>=1)
    {
        int via = deleteVertices[idx];
        for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
        }
      }

      int sum = 0;
      for(int i = n; i>=idx; i--){
        for(int j = n; j>=idx; j--){
            sum+= dist[deleteVertices[i]][deleteVertices[j]];
        }
      } 

      res.push_back(sum);
      idx--;
        
    }

    reverse(res.begin(), res.end());

    for(auto it: res){
        cout<<it<<" ";
    }

    cout<<endl;

    
}