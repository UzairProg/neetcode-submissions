class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mpp;
        unordered_map<char, int> mp;

        for(auto c: s){
            mpp[c]++;
        }
        for(auto c: t){
            mp[c]++;
        }

        if(mpp == mp){
            return true;
        }
        return false;
    }
};
