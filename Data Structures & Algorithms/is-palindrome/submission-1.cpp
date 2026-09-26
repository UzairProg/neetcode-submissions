class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j=s.length()-1;

        while(i<j){
            while(!(s[i]>= 'a' && s[i]<='z') &&
            !(s[i]>= 'A' && s[i]<='Z') && !(s[i]>='0' && s[i]<='9') && i<s.length()
            ){
                i++;
            }

            while(!(s[j]>= 'a' && s[j]<='z') &&
            !(s[j]>= 'A' && s[j]<='Z') && !(s[j]>='0' && s[j]<='9') && j>=0
            ){
                j--;
            }
            // cout << s[j] << " " << s[i] << " ";
            if((i<s.length() && j>=0) && (tolower(s[j]) != tolower(s[i]))){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
