class Solution {

    boolean isPossbile(int x, int[] nums, int k){
        int i = 0;
        boolean flag = false;

        while(i<nums.length){
            if(nums[i] <=x && flag == false){
                i++;
            }
        }
    }

    public int minCapability(int[] nums, int k) {

        int high = (int) 1e9;
        int low = 1;
        int res = -1;

        while(high >= low){
            int mid = high - (high-low)/2;

            if(isPossbile(mid, nums, k) == true){
                res = mid;
                high = mid-1;
            }

            else{
                low = mid+1;
            }
        }

        return res;
    }
}

public abstract class nej {
    
}
