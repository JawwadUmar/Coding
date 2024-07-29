#include <bits/stdc++.h>
using namespace std;

#define int long long 

vector<int> f(vector<int> &prefa, vector<int> &prefb, vector<int> &prefc, int target){
    int n = prefa.size();
    int x = target;
    vector<int> v;
    

    auto it = lower_bound(prefa.begin(), prefa.end(), x);
    if(it == prefa.end()){
        return {-1};
    }
    int idx = it - prefa.begin();
    
    v.push_back(1);
    v.push_back(idx+1);

    x = prefb[idx] + target;

    it = lower_bound(prefb.begin() + idx+1, prefb.end(), x);

    if(it == prefb.end()){
        return {-1};
    }

    v.push_back(idx+2);
    idx = it - prefb.begin();

    v.push_back(idx+1);
    

    x = prefc[idx] + target;

    it = lower_bound(prefc.begin(), prefc.end(), x);

    if(it == prefc.end()){
        return {-1};
    }

    v.push_back(idx+2);
    v.push_back(n);

    return v;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);

    vector<int> prefa(n);
    vector<int> prefb(n);
    vector<int> prefc(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
        
        if(i==0){
            prefa[i] = a[i];
        }

        else{
            prefa[i] = prefa[i-1] + a[i];
        }
    }

    for(int i = 0; i<n; i++){
        cin>>b[i];
        if(i==0){
            prefb[i] = b[i];
        }

        else{
            prefb[i] = prefb[i-1] + b[i];
        }
    }

    for(int i = 0; i<n; i++){
        cin>>c[i];
        if(i==0){
            prefc[i] = c[i];
        }

        else{
            prefc[i] = prefc[i-1] + c[i];
        }
    }

    int sum = prefa.back();
    int target = sum/3;

    if(sum%3){
        target+=1;
    }


    vector<int> temp = {-1};
    
    vector<int> v = f(prefa, prefb, prefc, target);

    if(v != temp){
        for(auto it: v){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }

    v = f(prefa, prefc, prefb, target);
    
    if(v != temp){
        cout<<v[0]<<" "<<v[1]<<" "<<v[4]<<" "<<v[5]<<" "<<v[2]<<" "<<v[3]<<endl;
        return;
    }

    v =f(prefb, prefa, prefc, target);
    if(v !=temp){
        cout<<v[2]<<" "<<v[3]<<" "<<v[0]<<" "<<v[1]<<" "<<v[4]<<" "<<v[5]<<endl;
        return;
    }

    v = f(prefb, prefc, prefa, target);
    
    if(v != temp){
        //B C A
        cout<<v[4]<<" "<<v[5]<<" "<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<endl;
        return;
    }

    v = f(prefc, prefa, prefb, target);
    if(v != temp){
        cout<<v[2]<<" "<<v[3]<<" "<<v[4]<<" "<<v[5]<<" "<<v[0]<<" "<<v[1]<<endl;
        return;
    }

    v = f(prefc, prefb, prefa, target);
    
    if(v!= temp){
        cout<<v[4]<<" "<<v[5]<<" "<<v[2]<<" "<<v[3]<<" "<<v[0]<<" "<<v[1]<<endl;
    }

    else{
        cout<<v.back()<<endl;
    }
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
}