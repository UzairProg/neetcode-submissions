class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1;
        while(i<j){
            if(nums[i] + nums[j] == target){
                return {i,j};
            }

            if(nums[i] > target){
                i++;
            }else{
                j--;
            }
        }
        return {-1,-1};
    }
};

/* 
Why It Fails
The array is unsorted: Two-pointer shrinking (i++ or j--) only guarantees finding a target when the array is monotonically ordered. In an unsorted array, moving pointers based on relative comparisons skips valid pairs unpredictably.

Flawed movement condition: if (nums[i] > target) i++ has no mathematical basis. If numbers are negative or if a large number needs a negative complement, comparing an individual element directly against target gives zero information about whether to advance i or decrement j.

Passing 2 test cases was pure coincidence: The pointer movements happened to land on the correct pair before hitting the termination condition by luck.
 */
