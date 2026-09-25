class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        bool zero_present = false;
        int zero_count = 0;
        for(const int num: nums){
            if(num != 0){
                prod *= num;
            }else{
                zero_present = true;
                zero_count++;
            }
        }
        vector<int> v;
        
        if(zero_count > 1){
            int len = nums.size();
            while(len > 0){
                v.push_back(0);
                len--;
            }
            return v;
        }
        

        for(int n: nums){
            if(zero_present && n != 0){
                v.push_back(0);
            }
            else if(n != 0){
                v.push_back(prod/n);
            }
            else{
                v.push_back(prod);
            }
        }
        return v;
    }
};
