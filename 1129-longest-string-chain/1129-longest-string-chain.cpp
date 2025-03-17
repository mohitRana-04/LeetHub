class Solution {
public:
    bool func(string a, string b){
            int n = a.size();
            int m = b.size();

            if(m-n !=1) return false;

            int i = 0, j = 0;
            while(i< n && j<m){
                if(a[i]==b[j]){
                    i++;
                }
                j++;
            }
            return i == n;
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();  // Sort words by length
        });
        vector<int> dp(words.size(), 1);
        int ans = 1;
        for(int i = 0; i< words.size(); i++){
            for(int j = 0; j< i; j++){
                if(func(words[j], words[i])){
                    dp[i] = max(dp[i], dp[j]+1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};