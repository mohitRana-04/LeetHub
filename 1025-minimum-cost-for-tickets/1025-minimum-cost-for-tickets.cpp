class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int last = days[n-1];
        int dp[last+1];

        dp[0] = 0;
        
        set<int> st(days.begin(), days.end());
        for(int i = 1; i<= last; i++){
            if(st.find(i) == st.end()){
                dp[i] = dp[i-1];
            } else{

            
                int d1 = costs[0] + dp[max(0, i-1)];  
                int d7 = costs[1] + dp[max(0, i-7)];  
                int d30 = costs[2] + dp[max(0, i-30)];
                

                dp[i] = min({d1, d7, d30});
            }
        }
        return dp[last];
    }
};