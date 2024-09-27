class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        set<string> st(bannedWords.begin(), bannedWords.end());
        int cnt = 0;
        for(auto x: message){
            if(st.find(x)!=st.end()) cnt++;
        }
        return cnt>1;

    }
};