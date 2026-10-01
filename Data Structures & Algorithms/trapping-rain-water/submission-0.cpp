class Solution {
public:
    int trap(vector<int>& height) {
        
        int left = 0;
        int right = 0;
        // skipping the starting overflow
        while(height[left] < height[right]){
            left++; right++;
        }

        int water = 0;
        int flag = false;
        int minWall = INT_MAX;

        for(; right<height.size(); right++){
            if(height[right] >= height[left]){
                minWall = min(height[left], height[right]);
                flag = true;
            }
            while(left != right && flag){
                if(height[left] < minWall){
                    water += minWall - height[left];
                }
                left++;
            }
            flag = false;
        }
        return water;
    }
};
/* 
if box->left == 0 && box.len > minWall overflow
else +1

keep 2 pointers firstly calc minWall then move towards the right one and calc water.. 
repeat till end
 */