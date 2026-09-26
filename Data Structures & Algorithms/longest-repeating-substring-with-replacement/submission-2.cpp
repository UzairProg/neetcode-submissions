class Solution {
public:
    int freqChar(vector<int>& v){
        int mostFreq = 0;
        for(int i=0; i<26; i++){
            mostFreq = max(mostFreq, v[i]);
        }
        return mostFreq;
    }
    int characterReplacement(string s, int k) {
        int l=0;
        int ans = 0;
        vector<int> v(26, 0); // freq

        for(int r=0; r<s.length(); r++){
            v[s[r] - 'A']++;
            int windowSize = r-l+1;
            if( windowSize - freqChar(v) <= k ){
                ans = max(ans, windowSize);
            }
            while(windowSize - freqChar(v) > k){
                v[s[l] - 'A']--;
                l++;
                windowSize = r-l+1;
            }
        }
        return ans;
    }
};
