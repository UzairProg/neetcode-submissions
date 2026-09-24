class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> v;
        for(string s: strs){
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());

            // if(v.count(sorted_s)){
                v[sorted_s].push_back(s);
            // }
        }

        vector<vector<string>> ans;
        for(const auto& pair: v){
            ans.push_back(pair.second);
        }

        return ans;
    }
};
