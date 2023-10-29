#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;
#define endl '\n'



bool isGood(string &s){
    int n = s.size();

    int i = 0;
    int j = n-1;

    while (j>=i)
    {
        if(s[i] == s[j]){
            return false;
        }

        i++;
        j--;
    }

    return true;
}

void add01(string &s, int j){

    int n = s.size();

    if(j<0){
        s = "01" + s;
        return;
    }

   

    string temp1 = s.substr(0, j+1);
    temp1+= "01";

    if(j+1 == n){
        s = temp1;
        return;
    }

    string temp2 = s.substr(j+1, n - (j+1));

    s= temp1 + temp2;
}


void solve(){

    int n;
    cin>>n;

    string s;
    cin>>s;

    if(n%2 != 0){
        cout<<-1<<endl;
        return;
    }

    if(isGood(s)){
        cout<<0<<endl;
        cout<<endl;

        return;
    }

    int p = 0;
    vector<int> res;

    while (p<= 300)
    {
        int i = 0;
        int j = s.size()-1;

        if(isGood(s)){
                
                //cout<<s<<endl;
                cout<<res.size()<<endl;
                for(auto it: res){
                    cout<<it<<" ";
                }
                cout<<endl;

                return;
            }

        while (j>i)
        {

        if(s[i] == s[j]){

            if(s[i] == '0'){
                add01(s, j);
                res.push_back(j+1);
                p++;
                j+=2;
                j--;
                i++;
            }

            else{
                add01(s, i-1);
                res.push_back(i);
                p++;
                i+=2;
                j+=2; //idk
                i--;
                j--;
            }

            if(p>300){
                cout<<-1<<endl;
                return;
            }

            if(isGood(s)){
                
                //cout<<s<<endl;
                cout<<res.size()<<endl;
                for(auto it: res){
                    cout<<it<<" ";
                }
                cout<<endl;

                return;
            }
        }

        else{

        i++;
        j--;
    }

    }

    }


    if(isGood(s)){
                
                //cout<<s<<endl;
                cout<<res.size()<<endl;
                for(auto it: res){
                    cout<<it<<" ";
                }
                cout<<endl;

                return;
    }

    cout<<-1<<endl;
    return;
    

    
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