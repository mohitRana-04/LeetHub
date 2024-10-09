class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.size() ==0) return 0;
        stack<char> st;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            } else{
                if(st.size() && st.top() == '('){
                    st.pop();
                } else{
                    st.push(s[i]);
                }
            }
        }
        return st.size();
    }
};