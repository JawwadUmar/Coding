#include <bits/stdc++.h>
using namespace std;

#define int long long

int check(string &s){
    stack<int> st;
    int ans = 0;

    for(int i =0; i<s.size(); i++){
        
        while(!st.empty() && i<s.size() && s[i] == ')' && s[st.top()] == '('){
            ans+= i - st.top();
            i++;
            st.pop();
        }

        if(i< s.size()){
            st.push(i);
        }
        
    }

    if(st.empty()){
        return ans;
    }

    return 1e18;
}

void solve(){
    int n;
    cin>>n;

    string s;
    cin>>s;

    string temp = s;
    //start filling it from left
    int countOpen = 0;
    int countClose = 0;

    for(int i = 0; i<n; i++){
        if(temp[i] == '_'){
            if(countOpen <= countClose){
                countOpen++;
                temp[i] = '(';
            }

            else{
                countClose++;
                temp[i] = ')';
            }
        }

        else if(temp[i] == '('){
            countOpen++;
        }

        else{
            countClose++;
        }
    }

    int ans1 = check(temp);
    
    temp = s;

    countOpen = countClose = 0;

    for(int i = n-1; i>=0; i--){
        if(temp[i] == '_'){
            if(countClose<= countOpen){
                countClose++;
                temp[i] = ')';
            }

            else{
                countOpen++;
                temp[i] = '(';
            }
        }
        else if(temp[i] == '('){
            countOpen++;
        }

        else{
            countClose++;
        }
    }

    int ans2 = check(temp);

    cout<<min(ans1, ans2)<<endl;
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while (t--)
    {
        /* code */
        solve();
    }
    
}