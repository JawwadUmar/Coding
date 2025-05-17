#include <bits/stdc++.h>
using namespace std;


int commonCards(int n, vector<int> &a, int m, vector<int> &b){
    
    map<int, int> mp1;
    map<int, int> mp2;

    for(auto it: a){
        mp1[it]++;
    }

    for(auto it: b){
        mp2[it]++;
    }

    int res = 0;

    for(int i = 0; i<b.size(); i++){
        if(mp2[b[i]] <=2){
            if(mp1[b[i]] <=2 && mp1[b[i]]!=0){
                res+= b[i];
            }
        }
    }

    return res;
}

int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    int m;
    cin>>m;
    vector<int> b(m);

    for(int i =0; i<m; i++){
        cin>>b[i];
    }

    cout<<commonCards(n, a, m, b)<<endl;
}