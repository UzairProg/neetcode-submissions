class Solution {
public:
    /* will not work as "," can be in string too
        eg: strs = ["hello,world", "hi"];
        our program will result in ["hello", "world", "hi"] which is wrong
        likewise other seprators will also not work
        like , . $ num cuz all of them might be in given string too
     */
    string encode(vector<string>& strs) {
        string ans = "";
        for(const string& str: strs){
            ans += str;
            ans += ",";
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string seg = "";
        for(char str: s){
            if(str == ','){
                ans.push_back(seg);
                seg = "";
                continue;
            }
            seg += (str);
        }
        return ans;
    }   
};
