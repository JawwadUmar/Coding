#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void rearrangeVector(vector<int> &nums, vector<vector<int>> &v){
        multiset<int> st;
        for(vector<int> &temp: v){
            st.insert(temp[1]);
        }

        for(vector<int>& temp: v){
            int val = temp[0];
            int idx = *(st.begin());
            nums[idx] = val;
            st.erase(st.begin());
        }
    }

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        vector<pair<int, int>> temp;
        for(int i =0; i<nums.size(); i++){
            temp.push_back({nums[i], i});
        }

        sort(temp.begin(), temp.end());

        int i =0;
        while (i<temp.size())
        {
            pair<int, int> grp = temp[i];
            int val = grp.first;
            int idx = grp.second;
            vector<vector<int>> v;
            int j = i;
            while (j<temp.size() && (temp[j].first - val) <=limit)
            {
                v.push_back({temp[j].first, temp[j].second});
                val = temp[j].first;
                idx = temp[j].second;
                j++;
            }

            rearrangeVector(nums, v);

            i = j;
        }
        
        return nums;

    }
};