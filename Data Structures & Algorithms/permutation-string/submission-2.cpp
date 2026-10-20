class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        int e = 0;
        int s = 0;

        // map<string, int> mp;
        vector<int> v(26, 0);
        vector<int> ans(26, 0);

        for(char s: s1){
            v[s - 'a']++;
        }

        for(; e<s1.size(); e++){
            ans[s2[e] - 'a']++;
        }
        if(ans == v){
            return true;
        }
        // e++;
        for(; e<s2.size(); e++){
            ans[s2[s] - 'a']--;
            ans[s2[e] - 'a']++;
            s++;
            if(ans == v){
                return true;
            }
        }
        return false;
    }
};
