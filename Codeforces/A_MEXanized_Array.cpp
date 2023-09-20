#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
        int n,k,x;
        cin>>n>>k>>x;
        if( n < k || k > x+1){
            cout<<-1<<"\n";
            
//             signed main(){
//     ios_base::sync_with_stdio(0);
//     cout.tie(0);
//     cin.tie(0);
    
//     int t;
//     // t=1;
//     cin>>t;
//     while(t--){
//        solve();
//     }
//     return 0;
// }
        }else{
            int i=0;
            int res = 0;
            for(i=0;i<k;i++){
                res+=i;
            }

//             signed main(){
//     ios_base::sync_with_stdio(0);
//     cout.tie(0);
//     cin.tie(0);
    
//     int t;
//     // t=1;
//     cin>>t;
//     while(t--){
//        solve();
//     }
//     return 0;
// }


            for(i;i<n;i++){
                if(x > k)
                    res+=x;
                else
                    res+=(k-1);
            }

            
//             signed main(){
//     ios_base::sync_with_stdio(0);
//     cout.tie(0);
//     cin.tie(0);
    
//     int t;
//     // t=1;
//     cin>>t;
//     while(t--){
//        solve();
//     }
//     return 0;
// }
            cout<<res<<"\n";
        }
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