class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){ // if not equal obv not a anagram
            return false;
        }
        vector<int> v(26, 0); // v(size, default val)  by default val is 0 anyways
// as given that "s and t consist of lowercase English letters. if all characters then v(256)" 
        
        for(int i=0; i<s.length(); i++){ // as len of both s & t are equal take any
            v[s[i] - 'a']++; // adding 1
            v[t[i] - 'a']--; // removing 1
        } // eventually all must be 0 if its an anagram else false

        for(int val: v){
            if(val != 0){ // if not zero then false
                return false;
            }
        }
        return true; // if all 0 then true
    }
};

/* 
#first thought 
- use xor operator "^" as it cancles outs the like ones.
- but that will not work, cuz same elems in same string might cancle out and still give true instead of false.
eg: s="aa" t="bb" 
thats why xor will not work
 */