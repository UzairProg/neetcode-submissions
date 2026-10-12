class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;

        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);
        
        // storing max left at block i.. easy just traverse
        int maxLft = height[0];
        for(int i=1; i<height.size(); i++){
            maxLft = max(maxLft, height[i-1]);
            maxLeft[i] = maxLft;
        }

        int maxRyt = height[height.size()-1];
        for(int i=height.size()-2; i>=0; i--){
            maxRyt = max(maxRyt, height[i+1]);
            maxRight[i] = maxRyt;
        }
        
        int ans = 0;
        for(int i=0; i<height.size(); i++){
            int calc = min(maxLeft[i], maxRight[i]) - height[i];
            if(calc > 0){
                ans += calc;
            }
        }
        return ans;
    }
};
/* 
at a given point of block, we want it's left max and right max
and min(left max, right max) - height of that point = water stored (only +ve values)

visualize it to understand better.. 
https://neetcode.io/problems/trapping-rain-water/question.. the given examples

min(max of 2 pillars around that point) - height 
simple logic! 
 */