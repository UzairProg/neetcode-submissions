class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mpp; // map

        for(const auto& i: nums){ // collection(nums[i] : frequency)
            mpp[i]++;
        }
        // now we cant sort map based on it values i.e(frequecny).. and key is the number so if we sort.. it'll be sorted by keys i.e(nums[i]), and its of no use for us

        vector<pair<int, int>> v; // thats why creating a vector
        for(const auto& [first, second]: mpp){ 
            v.push_back({second, first}); // adding values in reverse order so now its frequency : nums[i]
        }
        sort(v.rbegin(), v.rend()); // now if we sort.. it'll be sorted by frequency.. thats exactly what we want

        vector<int> ans(k);
        for(int i=0; i<k; i++){ // getting the first k elems as we wanted as ans
            ans[i] = v[i].second;
        }
        return ans;
    }
};
