class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(auto& str: strs){
            int len = str.length();
            ans += to_string(len) + "#" + str;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for(int i=0; i<s.length(); i++){
            int len = 0;
            while(s[i] != '#'){
                len = len*10 + (s[i] - '0');
                i++;
            }

            string seg = "";
            while(len > 0){
                seg += s[++i];
                len--;
            }
            ans.push_back(seg);
        }
        return ans;
    }
};
