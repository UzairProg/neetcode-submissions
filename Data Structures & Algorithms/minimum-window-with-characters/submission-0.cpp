class Solution {
public:
    bool isCapital(char c){
        if(c >= 'A' && c <= 'Z') return true;
        return false;
    }
    void skipper(int& i, string& s, vector<int>&setT){
        while(i<s.length()){ // for skipping initial char/s that are not in t
            if(isCapital(s[i]) && setT[s[i] - 'A'] == 0){
                i++;
            }
            else if(!isCapital(s[i]) && setT[s[i] - 'a' + 26] == 0){
                i++;
            }
            else{
                break;
            }
        }
    }
    string minWindow(string s, string t) {
        vector<int> setT(52, 0);
        for(auto c: t){
            if(isCapital(c)){ 
                setT[c - 'A']++;
            }
            else{
                setT[c - 'a' + 26]++;
            }  
        }

        int i=0;
        skipper(i,s,setT);
        
        vector<int> seen(52, 0);
        string answerf = "";
        string ans = "";
        for(; i<s.length(); i++){
            ans += s[i];
            if(isCapital(s[i])){
                seen[s[i] - 'A']++;
            }
            else{
                seen[s[i] - 'a' + 26]++;
            }

            if(checkIfAns(seen, setT, answerf, ans)){
                // cout << "i:" << i << " ans:" << ans.length() << " - ";
                i = (i-ans.length())+2;
                skipper(i,s,setT);
                fill(seen.begin(), seen.end(), 0); 
                ans = "";
                i--;
            }
        }
        return answerf;
    }

    bool checkIfAns(vector<int>& seen, vector<int>& setT, string& answerf, string ans){
        // cout << ans;
        for(int i=0; i<52; i++){
            if(!(seen[i] >= setT[i])){
                return false;
            }
        }
        if(answerf.empty()) answerf = ans;
        if(answerf.length() > ans.length()){ 
            answerf = ans;
        }
        return true;
    }
};
/* my approach
first make hash set of t
then loop through str s
maintian hashset of substr
if(substr.len < t.len) obv not the ans 
else{ // can be an ans
    compare hash of subs with hash of t.. how?
    t[0] == subs[0] likewise whole t
}

 */