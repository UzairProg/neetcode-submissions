class Solution {
public:
    vector<pair<int, int>> twoSum(const vector<int>& nums, int target, int i){
        vector<pair<int, int>> ans;
        int j=nums.size()-1;
        i++;
        while(i<j){
            int sum = nums[i] + nums[j];

            if(sum == target){
                ans.push_back({i,j});

                while(i<j && nums[i+1] == nums[i]){
                    i++;
                }

                while(i<j && nums[j-1] == nums[j]){
                    j--;
                }
                i++;
                j--;
            }

            if(sum > target){
                j--;
            }
            else if(sum < target){
                i++;
            }
        }
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for(int i=0; i<nums.size(); i++){
            while(i>0 && i<nums.size()-1 && (nums[i-1] == nums[i])){
                i++;
            }
            int target = -(nums[i]);

           vector<pair<int, int>> p = twoSum(nums, target, i);
            if(!p.empty()){
                for(auto& it: p){
                    ans.push_back({ nums[i], nums[it.first], nums[it.second] });
                }
            }
        }
        return ans;
    }
};
