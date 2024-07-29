#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){

    int n;
    cin>>n;

    string s;
    cin>>s;

    int ans = 1e18;

    for(int i = 0; i<n-1; i++){
        string temp = "";
        temp+=s[i];
        temp+=s[i+1];
        int x = stoll(temp);
        int y = 0;

        for(int j = 0; j<n; j++){
            if(j == i || j== i+1){

                if(j == i+1 && j ==1){
                    y = x;
                    continue;
                }
                if(j == i+1){

                
                if(x<=1){
                    y = y*x;
                }
                else{
                    if(y<=1){
                        y = y*x;
                    }
                    else{
                        y = y+x;
                    }
                    
                }
                }
                continue;
            }

            if(j == 0){
                y = s[j] - '0';
                continue;
            }

            else if(s[j] <='1'){
                y = y*(s[j] - '0');
            }

            else{
                if(y<=1){
                    y = y*(s[j] - '0');
                }

                else{
                    y = y+ (s[j] - '0');
                }
                
            }
        }

        ans = min(ans, y);
    }

    cout<<ans<<endl;
    
}

signed main(){
    int t;
    cin>>t;

    while (t--)
    {
        solve();
    }
        
}