
#include <bits/stdc++.h>
using namespace std;

//A Question where you need monotonic stack

class Solution {
public:
    bool find132pattern(vector<int>& nums) {

        //nums[i] < nums[k] < nums[j]
        //i < j < k

        int numj = INT_MIN;

        stack<int> st;

        for(int i  = nums.size() -1; i>= 0; i--){
            if(nums[i] < numj){
                return true;
            }

            while (!st.empty() && nums[i] > st.top())
            {
                numj = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};
// @lc code=end

