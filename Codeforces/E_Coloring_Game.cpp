#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isBipartite(int node, vector<int> adj[],vector<int> &vis, vector<int> &colorof, int color){
    vis[node] = 1;
    colorof[node] = color;
    bool flag = true;
 
    for(auto it: adj[node]){
        if(!vis[it]){
             flag =  isBipartite(it, adj, vis, colorof, 1-color);
        }
 
        else if(colorof[it] == colorof[node]){
            flag = false;
        }
    }
 
    return flag;
}

void solve(){
    int n, m;
    cin>>n>>m;

    vector<int> adj[n+1];

    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n+1, 0);
    vector<int> colorof(n+1, -1);
    bool flag = isBipartite(1, adj, vis,colorof, 0);

    

    if(flag == false){
        cout<<"Alice"<<endl;

        while (n--)
        {
            cout<<"1 2"<<endl;
            int node, col;
            cin>>node>>col;
        }

        return;
    }
    vector<int> color1;
    vector<int> color2;


    for(int i = 1; i<=n; i++){
        if(colorof[i] == 0){
            color1.push_back(i);
        }

        else{
            color2.push_back(i);
        }
    }

    cout<<"Bob"<<endl;
    int i = 0;
    int j = 0;

    while (n--)
    {
        int c1, c2;
        cin>>c1>>c2;
        if(c1> c2){
            swap(c1, c2);
        }

        if(c1 == 1){
            if(i<color1.size()){
            cout<<color1[i]<<" "<<c1<<endl;
            i++;
        }

        else{
            cout<<color2[j]<<" "<<c2<<endl;
            j++;
        }

        }

        else{
            if(j<color2.size()){
                cout<<color2[j]<<" "<<c1<<endl;
                j++;
            }

            else{
                cout<<color1[i]<<" "<<c2<<endl;
                i++;
            }
        }
    }
}

signed main(){

    
    int t;
    t = 1;
    cin>>t;

    while (t--)
    {
        solve();
    }
    
    

}
