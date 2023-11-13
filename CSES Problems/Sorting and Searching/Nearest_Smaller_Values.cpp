#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    vector<int> res(n, 0);

    stack<int> st;

    for(int i = n-1; i>=0; i--){

        while (!st.empty() && a[i] < a[st.top()])
        {
            res[st.top()] = i+1;
            st.pop();
        }

        st.push(i);
    }

    for(auto it: res){
        cout<<it<<" ";
    }
    cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}