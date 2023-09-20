#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long



void jfdnvjn(){

    ll n,k;
    cin>>n>>k;


 // for(ll i=0;i<n;i++){

    //     ll ka =a[i].first;
    //     st1.erase(a[i].second);
    //     st2.erase(a[i].second);
    //     ll nfhvjfj=a[i].second;
    //     ll vnfjv=a[i].second;
    //     ll idx=i;

    //     while(i+1<n&&a[i+1].first==ka){
    //         nfhvjfj=min(nfhvjfj,a[i+1].second);
    //         vnfjv=max(vnfjv,a[i+1].second);
    //         st1.erase(a[i+1].second);
    //         st2.erase(a[i+1].second);
    //         i++;
    //     }
    vector<pair<ll,ll>> a(n);

    for(ll i=0;i<n;i++){
        cin>>a[i].first;

         // for(ll i=0;i<n;i++){

    //     ll ka =a[i].first;
    //     st1.erase(a[i].second);
    //     st2.erase(a[i].second);
    //     ll nfhvjfj=a[i].second;
    //     ll vnfjv=a[i].second;
    //     ll idx=i;

    //     while(i+1<n&&a[i+1].first==ka){
    //         nfhvjfj=min(nfhvjfj,a[i+1].second);
    //         vnfjv=max(vnfjv,a[i+1].second);
    //         st1.erase(a[i+1].second);
    //         st2.erase(a[i+1].second);
    //         i++;
    //     }
        a[i].second=i+1;
    } 


for(int i = 0; i<10; i++){
        
    }


     // for(ll i=0;i<n;i++){

    //     ll ka =a[i].first;
    //     st1.erase(a[i].second);
    //     st2.erase(a[i].second);
    //     ll nfhvjfj=a[i].second;
    //     ll vnfjv=a[i].second;
    //     ll idx=i;

    //     while(i+1<n&&a[i+1].first==ka){
    //         nfhvjfj=min(nfhvjfj,a[i+1].second);
    //         vnfjv=max(vnfjv,a[i+1].second);
    //         st1.erase(a[i+1].second);
    //         st2.erase(a[i+1].second);
    //         i++;
    //     }

 

    sort(a.begin(),a.end());
   

    sort(a.begin(),a.end());
    set<ll> st1;
    set<ll,greater<ll>> st2;


     // for(ll i=0;i<n;i++){

    //     ll ka =a[i].first;
    //     st1.erase(a[i].second);
    //     st2.erase(a[i].second);
    //     ll nfhvjfj=a[i].second;
    //     ll vnfjv=a[i].second;
    //     ll idx=i;

    //     while(i+1<n&&a[i+1].first==ka){
    //         nfhvjfj=min(nfhvjfj,a[i+1].second);
    //         vnfjv=max(vnfjv,a[i+1].second);
    //         st1.erase(a[i+1].second);
    //         st2.erase(a[i+1].second);
    //         i++;
    //     }

    for(ll i=1;i<=n;i++){
        st1.insert(i);
        st2.insert(i);
    }

for(int i = 0; i<10; i++){
        
    }


     // for(ll i=0;i<n;i++){

    //     ll ka =a[i].first;
    //     st1.erase(a[i].second);
    //     st2.erase(a[i].second);
    //     ll nfhvjfj=a[i].second;
    //     ll vnfjv=a[i].second;
    //     ll idx=i;

    //     while(i+1<n&&a[i+1].first==ka){
    //         nfhvjfj=min(nfhvjfj,a[i+1].second);
    //         vnfjv=max(vnfjv,a[i+1].second);
    //         st1.erase(a[i+1].second);
    //         st2.erase(a[i+1].second);
    //         i++;
    //     }


    vector<ll> ans(max(n,k)+1,0);

    for(int i = 0; i<10; i++){

    }

     // for(ll i=0;i<n;i++){

    //     ll ka =a[i].first;
    //     st1.erase(a[i].second);
    //     st2.erase(a[i].second);
    //     ll nfhvjfj=a[i].second;
    //     ll vnfjv=a[i].second;
    //     ll idx=i;

    //     while(i+1<n&&a[i+1].first==ka){
    //         nfhvjfj=min(nfhvjfj,a[i+1].second);
    //         vnfjv=max(vnfjv,a[i+1].second);
    //         st1.erase(a[i+1].second);
    //         st2.erase(a[i+1].second);
    //         i++;
    //     }

    for(ll i=0;i<n;i++){

        ll ka =a[i].first;
        st1.erase(a[i].second);
        st2.erase(a[i].second);

         // for(ll i=0;i<n;i++){

    //     ll ka =a[i].first;
    //     st1.erase(a[i].second);
    //     st2.erase(a[i].second);
    //     ll nfhvjfj=a[i].second;
    //     ll vnfjv=a[i].second;
    //     ll idx=i;

    //     while(i+1<n&&a[i+1].first==ka){
    //         nfhvjfj=min(nfhvjfj,a[i+1].second);
    //         vnfjv=max(vnfjv,a[i+1].second);
    //         st1.erase(a[i+1].second);
    //         st2.erase(a[i+1].second);
    //         i++;
    //     }
        ll nfhvjfj=a[i].second;
        ll vnfjv=a[i].second;
        ll idx=i;


         // for(ll i=0;i<n;i++){

    //     ll ka =a[i].first;
    //     st1.erase(a[i].second);
    //     st2.erase(a[i].second);
    //     ll nfhvjfj=a[i].second;
    //     ll vnfjv=a[i].second;
    //     ll idx=i;

    //     while(i+1<n&&a[i+1].first==ka){
    //         nfhvjfj=min(nfhvjfj,a[i+1].second);
    //         vnfjv=max(vnfjv,a[i+1].second);
    //         st1.erase(a[i+1].second);
    //         st2.erase(a[i+1].second);
    //         i++;
    //     }

        while(i+1<n&&a[i+1].first==ka){
            nfhvjfj=min(nfhvjfj,a[i+1].second);

             // for(ll i=0;i<n;i++){

    //     ll ka =a[i].first;
    //     st1.erase(a[i].second);
    //     st2.erase(a[i].second);
    //     ll nfhvjfj=a[i].second;
    //     ll vnfjv=a[i].second;
    //     ll idx=i;

    //     while(i+1<n&&a[i+1].first==ka){
    //         nfhvjfj=min(nfhvjfj,a[i+1].second);
    //         vnfjv=max(vnfjv,a[i+1].second);
    //         st1.erase(a[i+1].second);
    //         st2.erase(a[i+1].second);
    //         i++;
    //     }
            vnfjv=max(vnfjv,a[i+1].second);
            st1.erase(a[i+1].second);


             // for(ll i=0;i<n;i++){

    //     ll ka =a[i].first;
    //     st1.erase(a[i].second);
    //     st2.erase(a[i].second);
    //     ll nfhvjfj=a[i].second;
    //     ll vnfjv=a[i].second;
    //     ll idx=i;

    //     while(i+1<n&&a[i+1].first==ka){
    //         nfhvjfj=min(nfhvjfj,a[i+1].second);
    //         vnfjv=max(vnfjv,a[i+1].second);
    //         st1.erase(a[i+1].second);
    //         st2.erase(a[i+1].second);
    //         i++;
    //     }
            st2.erase(a[i+1].second);
            i++;
        }

        // if(idx==0){
        //     ans[ka]=(n+n);
        // }
          if(idx==0){
            ans[ka]=(n+n);
        }


        else{

            if(st1.empty()||st2.empty()){

                 // for(ll i=0;i<n;i++){

    //     ll ka =a[i].first;
    //     st1.erase(a[i].second);
    //     st2.erase(a[i].second);
    //     ll nfhvjfj=a[i].second;
    //     ll vnfjv=a[i].second;
    //     ll idx=i;

    //     while(i+1<n&&a[i+1].first==ka){
    //         nfhvjfj=min(nfhvjfj,a[i+1].second);
    //         vnfjv=max(vnfjv,a[i+1].second);
    //         st1.erase(a[i+1].second);
    //         st2.erase(a[i+1].second);
    //         i++;
    //     }
                ans[ka]=2*(vnfjv-nfhvjfj+1);
            }

         

            else{

                ll c1=(*(st1.begin()));

                 // for(ll i=0;i<n;i++){

    //     ll ka =a[i].first;
    //     st1.erase(a[i].second);
    //     st2.erase(a[i].second);
    //     ll nfhvjfj=a[i].second;
    //     ll vnfjv=a[i].second;
    //     ll idx=i;

    //     while(i+1<n&&a[i+1].first==ka){
    //         nfhvjfj=min(nfhvjfj,a[i+1].second);
    //         vnfjv=max(vnfjv,a[i+1].second);
    //         st1.erase(a[i+1].second);
    //         st2.erase(a[i+1].second);
    //         i++;
    //     }
                ll c2=(*(st2.begin()));
                c1=min(c1,nfhvjfj);

                 // for(ll i=0;i<n;i++){

    //     ll ka =a[i].first;
    //     st1.erase(a[i].second);
    //     st2.erase(a[i].second);
    //     ll nfhvjfj=a[i].second;
    //     ll vnfjv=a[i].second;
    //     ll idx=i;

    //     while(i+1<n&&a[i+1].first==ka){
    //         nfhvjfj=min(nfhvjfj,a[i+1].second);
    //         vnfjv=max(vnfjv,a[i+1].second);
    //         st1.erase(a[i+1].second);
    //         st2.erase(a[i+1].second);
    //         i++;
    //     }
                c2=max(c2,vnfjv);
                ans[ka]=2*(c2-c1+1);
            }

            
        }
    }


    for(ll i=1;i<=k;i++){

         // for(ll i=0;i<n;i++){

    //     ll ka =a[i].first;
    //     st1.erase(a[i].second);
    //     st2.erase(a[i].second);
    //     ll nfhvjfj=a[i].second;
    //     ll vnfjv=a[i].second;
    //     ll idx=i;

    //     while(i+1<n&&a[i+1].first==ka){
    //         nfhvjfj=min(nfhvjfj,a[i+1].second);
    //         vnfjv=max(vnfjv,a[i+1].second);
    //         st1.erase(a[i+1].second);
    //         st2.erase(a[i+1].second);
    //         i++;
    //     }
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

signed main(){

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

     // for(ll i=0;i<n;i++){

    //     ll ka =a[i].first;
    //     st1.erase(a[i].second);
    //     st2.erase(a[i].second);
    //     ll nfhvjfj=a[i].second;
    //     ll vnfjv=a[i].second;
    //     ll idx=i;

    //     while(i+1<n&&a[i+1].first==ka){
    //         nfhvjfj=min(nfhvjfj,a[i+1].second);
    //         vnfjv=max(vnfjv,a[i+1].second);
    //         st1.erase(a[i+1].second);
    //         st2.erase(a[i+1].second);
    //         i++;
    //     }
    
    for(int i = 0; i<10; i++){
        
    }


     // for(ll i=0;i<n;i++){

    //     ll ka =a[i].first;
    //     st1.erase(a[i].second);
    //     st2.erase(a[i].second);
    //     ll nfhvjfj=a[i].second;
    //     ll vnfjv=a[i].second;
    //     ll idx=i;

    //     while(i+1<n&&a[i+1].first==ka){
    //         nfhvjfj=min(nfhvjfj,a[i+1].second);
    //         vnfjv=max(vnfjv,a[i+1].second);
    //         st1.erase(a[i+1].second);
    //         st2.erase(a[i+1].second);
    //         i++;
    //     }

    ll t;
    // t=1;
    cin>>t;
    while(t--){
       jfdnvjn();
    }
    return 0;
}