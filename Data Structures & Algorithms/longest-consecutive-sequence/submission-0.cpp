class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int ans = 0;
        for(int n: s){
            if(s.find(n-1) == s.end()){
                int count = 1;
                while(s.find(n+count) != s.end()){
                    count++;
                }
                ans = max(count, ans);
            }
        }
        return ans;
    }
};
