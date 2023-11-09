#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
#define endl '\n'


void solve(){

    int len;
    cin>>len;

    int n;
    cin>>n;

    multiset<int> m;

    m.insert(0);
    m.insert(len);

    multiset<int, greater<int>> st;

    st.insert(len);

    for(int i = 0; i<n; i++){
        int pos;
        cin>>pos;

        auto it = m.lower_bound(pos);
        
        int right = *it;
        it--;

        int left = *it;

        // cout<<pos<<" "<<left<<" "<<right<<endl;

        int newLen1 = pos-left;
        int newLen2 = right-pos;

        auto pit = st.find(right - left);
        if (pit != st.end()) {
        st.erase(pit);
        }

        st.insert(newLen1);
        st.insert(newLen2);

        m.insert(pos);

        cout<<*(st.begin())<<" ";

    }

    // cout<<"here"<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t = 1;
    // cin>>t;
    while(t--){
       solve();
    }
    return 0;
}