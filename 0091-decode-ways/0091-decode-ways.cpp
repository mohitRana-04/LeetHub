class Solution {
public:
    int dp [102];
    int helper(string s, int ind){
        if(ind == s.size()) return 1;

        if(s[ind] == '0') return 0;

        if(dp[ind]) return dp[ind];

        int f = 0, se =0;

        f = helper(s, ind+1);

        if(ind+1<s.size() && (s[ind] == '1' || (s[ind]=='2' && s[ind+1]<'7'))){
            se = helper(s, ind+2);
        }
        return dp[ind] = f+se;


    }

    int numDecodings(string s) {
        for(int i = 0; i< 102; i++) dp[i] = 0;
        return helper(s, 0);
    }
};