class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // 2 passes prefix and and suffix
        /* 
        arr = [1,2,3,4]

        # 1st pass - prefix first
        res = [1,1,2,6]

        # 2nd pass - & suffix
        res = [1*24, 1*12, 2*4, 6*1]

        and we got the ans - prefix * suffix
        res = [24,12,8,6]
         */

        vector<int> res(nums.size(), 1);

        // #1st pass
        int prefix_prod = 1;
        for(int i=0; i<nums.size(); i++){
            res[i] = prefix_prod;
            prefix_prod *= nums[i];
        }

        // #2nd pass
        int suffix_prod = 1;
        for(int i=nums.size()-1; i>=0; i--){
            res[i] *= suffix_prod;
            suffix_prod *= nums[i];
        }
        
        return res;
    }
};
