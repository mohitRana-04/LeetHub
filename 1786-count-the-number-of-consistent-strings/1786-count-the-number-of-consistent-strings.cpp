class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> st(allowed.begin(), allowed.end());
        int ans = 0;
        for(auto& x : words) {
            bool check = true;
            for(auto& y : x) {
                if(st.find(y) == st.end()) {
                    check = false;
                    break;  // No need to check further characters in this word
                }
            }
            if(check) ans++;  // Increment ans only if the whole word is valid
        }
        return ans;
    }
};