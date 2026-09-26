class Solution {
public:
/* jo new char aa rha hai, ky wo seen me already present hai? if yes fir wo char ko eliminate kro lhs se.. 
eg: abbc .. set = {a,b} as both unique
now @ index 2 i.e 'b'.. we get see.count(s[r]) as true for we remove seen[l] i.e 'a' then check again (set now: {b}) b still present.. then we again remove seen[l] i.e b.. now set empty.. not present and we again append the new b later after while
             */
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int maxSubStr = 0;
        unordered_set<char> seen;

        for(int r=0; r<s.length(); r++){
            
            while(seen.count(s[r])){
                seen.erase(s[l]);
                l++;
            }

            seen.insert(s[r]);
            maxSubStr = max(maxSubStr, r-l + 1); // or max(maxSubStr, seen.size()); as seen also have exact amount of uniuqe elems rn. doing +1 cuz eg: ab (1-0) = 1.. longest is 2. as we're using 0 indexed thats why +1;
        }

        return maxSubStr; // return max count! easyy
    }
};
