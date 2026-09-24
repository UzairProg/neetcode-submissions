class Solution {
public:
    /* adding len of a str before so while decoding its easy */
    string encode(vector<string>& strs) {
        string ans = "";
        for(auto& str: strs){
            ans += (str.length());
            ans += str;
        }
        cout << ans;
        return ans;
    }

    vector<string> decode(string s) {
        if (s.length() <= 1) return {""};
        vector<string> ans;

        int len = s[0];
        string seg = "";
        for(int i=1; i<s.length(); i++){
            seg += s[i];
            len--;
            if(len == 0){
                ans.push_back(seg);
                seg = "";
                len = s[++i];
            }
        }
        return ans;
    }
};
