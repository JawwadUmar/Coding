#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findSqrt(int x){
        int low = 1;
        int high = x;

        while (high>=low)
        {
            int mid = (low+high)/2;
            if(mid*1ll*mid == 1ll*x){
                return mid;
            }

            else if(mid*1ll*mid > 1ll*x){
                high = mid-1;
            }
            else{
                low= mid+1;
            }
        }

        return -1;
        
    }

    int f(int x, unordered_map<int, int>&mp){
       
        int sqrtx = findSqrt(x);
        if(sqrtx == -1){
            return 0;
        }

        if(mp.find(sqrtx) == mp.end()){
            return 0;
        }

        if(mp[sqrtx] < 2){
            return 0;
        }

        return 2 + f(sqrtx, mp);
        
    }
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int x: nums){
            mp[x]++;
        }

        // for(auto it: mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }

        int res = mp[1];
        if(res!=0 && res%2 == 0){
            res--;
        }

        mp.erase(1);

        cout<<mp[81]<<endl;

        for(pair<int, int> p: mp){
            int x = p.first;
            if(x == 81){
                cout<<"here"<<endl;
                cout<<f(x, mp)<<endl;
            }
            res = max(res, 1 + f(x, mp));

        }

        return res;

    }
};