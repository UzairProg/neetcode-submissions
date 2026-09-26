class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        unordered_map<char, char> mp = { 
            {')', '('}, 
            {'}', '{'}, 
            {']', '['} 
        }; 
        
        for(auto c: s){
            if(c == '(' || c == '[' || c == '{'){
                st.push(c);
            }

            else if(!st.empty() && mp[c] == st.top()){
                st.pop();
            }else{ 
                return false; 
            } 
        }
        if(st.empty()) return true;
        return false;
    }
};
