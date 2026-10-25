class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        vector<int> hashT(256, 0);

        for(char c: t){
            hashT[c]++;
        }

        int startIdx = 0;
        int endIdx = INT_MAX;
        int count = 0;
        int start = 0;
        int i = 0;

        while(i < s.size()){

            if(count < t.size()){ // if count is less.. case not satisfied.. add more chars
                if(hashT[s[i]] > 0) count++;
                hashT[s[i]]--;
                i++;
            }

            while(count >= t.size()){
                if(count == t.size()){
                    if((i - start) < (endIdx - startIdx)){
                        startIdx = start;
                        endIdx = i;
                    }
                }
                    hashT[s[start]]++;
                    if(hashT[s[start]] > 0) count--;
                    start++;
                }

        }
        
        return (endIdx == INT_MAX) ? "" : s.substr(startIdx, endIdx - startIdx);
    }
};