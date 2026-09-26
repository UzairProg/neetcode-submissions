class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0;
        int j=heights.size()-1;

        int maxA = 0;
        while(i<j){
            int calc = (j-i) * min(heights[i], heights[j]);
            if(heights[i] <= heights[j]){
                i++;
            }
            else{
                j--;
            }
            maxA = max(maxA, calc);
        }
        return maxA;
    }
};
