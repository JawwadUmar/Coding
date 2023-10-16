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

//ctrl shift B for output

int numberOfSetBits(int n){
    return __builtin_popcount(n);
}

int findLevel(int pos, int n){

    int i = 0;
    int level = 0;

    while (i<pos)
    {
        i+=n;
        level++;
        n--;
    }

    return level;
}

string findString(string &s, int to_remove){

    int n = s.size();
    int len = n -to_remove;

    stack<char> st;

    int i;

    for(i = 0; i<n; i++){

        while (!st.empty() && s[i]<st.top() && to_remove>0)
        {
            st.pop();
            to_remove--;

            if(to_remove == 0){
                break;
            }
        }

        st.push(s[i]);
    }


    string res = "";

    while (!st.empty())
    {
        res+= st.top();
        st.pop();
    }

    reverse(res.begin(), res.end());

    i++;

    while (i<n)
    {
        res+= s[i];
        i++;
    }

    return res.substr(0, len-1);
}

int findStarting(int n, int level){

    int i = 0;
    int cnt = 1;

    while (level--)
    {
        i+= cnt;
        cnt= n;
        n--;
    }

    return i;
}


void solve(){

    string s;
    cin>>s;

    int pos;
    cin>>pos;

    int n = s.size();

    int level = findLevel(pos, n);

    // cout<<level<<endl;

    //remove level-1 chars from s to make it smallest

    char c = 'a' -1;
    s.push_back(c);

    string temp = findString(s, level-1);
    // cout<<temp<<endl;

    int startingPos = findStarting(n, level);

    // cout<<startingPos<<endl;

    cout<<temp[pos - startingPos];




}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t = 1;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;
}