#include<bits/stdc++.h>
using namespace std;

struct PairComparator {
    bool operator() (const std::pair<int, int>& p1, const std::pair<int, int>& p2) const {
        if (p1.first > p2.first) {
            return true;
        } else if (p1.first == p2.first) {
            return p1.second < p2.second;
        }
        return false;
    }
};

class Solution{
    
    public:
    
    static bool cmp(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
        if (p1.first > p2.first) {
            return true;
        } else if (p1.first == p2.first) {
            return p1.second < p2.second;
        }
        return false;
    }
        vector<vector<int>> minCashFlow(vector<vector<int>> &transaction, int n)
        {
            map<int, int> mp;
            
            for(int i = 0; i<transaction.size(); i++){
                for(int j = 0; j<transaction.size(); j++){
                    
                    //i took from j
                    mp[i]+= transaction[i][j];
                    mp[j]-= transaction[i][j];
                    
                    transaction[i][j] = 0;
                    
                }
            }
            
    
            multiset<pair<int, int>> m1;
            std::multiset<std::pair<int, int>, PairComparator> m2;


            
            for(auto it: mp){
                if(it.second <0){
                    m1.insert({it.second, it.first});
                }
                
                else if(it.second> 0){
                    m2.insert({it.second, it.first});
                }
            }
            
            
            
            while(!m2.empty()){
                
                auto it1 = m1.begin();
                auto it2 = m2.begin();
                
                int j = it1->second; //dene wala
                int i = it2->second; //lene wala
                
                int amount1 = it1->first; //j ne itna diya h 
                int amount2 = it2->first; // i ne itna liya h 
                
                m1.erase(it1);
                m2.erase(it2);
                
                if(abs(amount1) > abs(amount2)){
                    //j ne zyda de diya h
                    transaction[i][j]+= abs(amount2);
                    m1.insert({amount1+ amount2, j});
                }
                
                else if(abs(amount1) < abs(amount2)){
                    //i ne zyda leliya h
                    transaction[i][j]+= abs(amount1);
                    m2.insert({amount1+ amount2, i});
                }
                
                else{
                    transaction[i][j]+= abs(amount1);
                }
                
            }
            
            // cout<<res<<endl;
            
            return transaction;
        }
        
        
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> g(n,vector<int> (n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cin>>g[i][j];
        }
        Solution s;
        vector<vector<int>> r=s.minCashFlow(g,n);
        for(auto j:r)
        {
            for(auto i:j)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}
