class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int start = 0;

        for(int i=k-1; i<nums.size(); i++){
            int maxi = INT_MIN;
            for(int j=start; j<=i; j++){
                maxi = max(maxi, nums[j]);
            }
            ans.push_back(maxi);
            start++;
        }

        return ans;
    }
};
