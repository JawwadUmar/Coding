#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
#define endl '\n'

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


bool possible(int wins, string &s, char c){

    map<char, int> mp;
    int i = 0;
    int n = s.size();

    char complement = c^'A'^'B';

    while (i<s.size())
    {
        int cnt1 = 0;
        int cnt2 = 0;
        int j = i;

        while (j<n && cnt1 < wins && cnt2 < wins)
        {
            if(s[j] == 'A'){
                cnt1++;
            }

            else{
                cnt2++;
            }

            j++;
        }

        if(cnt1 == wins){
            mp['A']++;
        }

        else if(cnt2 == wins){
            mp['B']++;
        }

        else{
            return false;
        }

        i = j; 
    }

    return mp[s.back()] > mp[complement];
}


void solve(){

    int n;
    cin>>n;

    string s;
    cin>>s;


    int cntA = 0;

    for(int i = 0; i<n; i++){
        if(s[i] == 'A'){
            cntA++;
        }
    }

    int cntB = n - cntA;

    char endswith = s.back();

    if(endswith == 'B'){

        if(cntB > cntA){
            cout<<'B'<<endl;
            return;
        }

        for(int i = 1; i<=cntB; i++){

            if(possible(i, s, s.back())){

                cout<<'B'<<endl;
                return;
            }
        }

        cout<<"?"<<endl;
        return;
    }

    else if(endswith == 'A'){

        if(cntB < cntA){
            cout<<'A'<<endl;
            return;
        }

        for(int i = 1; i<=cntB; i++){

            if(possible(i, s, s.back())){

                cout<<'A'<<endl;
                return;
            }
        }

        cout<<"?"<<endl;
        return;
    }


    
    
    
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




// 1
// 20
// AAAAAAAABBBAABBBBBAB