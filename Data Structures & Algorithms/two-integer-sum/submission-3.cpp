class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> s;
        // for(int i=0; i<nums.size(); i++){ #1
        //     if(!s.empty()){
        //         auto j = s.find(nums[i]);
        //         if(j != s.end()){
        //             return {j->second, i};
        //         }
        //     }
        //     s.insert({target-nums[i], i});
        // }

        // #2 
        for(int i=0; i<nums.size(); i++){
            int complement = target - nums[i];
            if(s.count(complement)){
                return {s[complement], i};
            }
            s.insert({nums[i], i});
        }

        return {-1, -1};
        // both method works! and are the same thing
    }
};

