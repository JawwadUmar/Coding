#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
int binaryExponentiation(int x, int p){
    int res = 1;
    while(p){
        if(p%2){
            res = (res * x)%MOD;
        }

        x = (x*x)%MOD;
        p = p/2;
    }
    
    return res;
}

void solve(){
    int n, k;
    cin>>n>>k;

    int ans = 0;

    vector<int> a(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];

        if(a[i] <=k){
            ans = 1;
        }
    }

    vector<int> heights(n);

    for(int i = 0; i<n; i++){
        cin>>heights[i];
    }

    if(ans == 0){
        cout<<0<<endl;
        return;
    }


    while (n>=1 && a[n-1] > k)
    {
        n--;
    }

    queue<int> q;
    int last = heights[n-1];
    int cnt = 1;
    int fruits = a[n-1];
    q.push(a[n-1]);

    for(int i = n-2; i>=0; i--){

        last = heights[i+1];

        if(heights[i]%last == 0){

            while (!q.empty() && fruits+a[i] >k)
            {
                fruits = fruits - q.front();
                q.pop();
                cnt--;
                ans = max(ans, cnt);
            }
            
            if(fruits+ a[i] <=k){
                fruits+= a[i];
                cnt++;
                ans = max(ans, cnt);
                q.push(a[i]);
            }  
        }

        else{

            
            while(q.size()){
                q.pop();
            }

            cnt = 0;
            fruits = 0;

            if(a[i] <= k){
                cnt++;
                // cout<<i<<endl;
                q.push(a[i]);
                fruits+= a[i];
                ans = max(ans, cnt);
            }

            else{
                continue;
            }

        }

    }

    ans = max(ans, cnt);

    cout<<ans<<endl;
    
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