class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int dp[3] = {0,0,0} ;
       
        for(int i = 0; i< bills.size(); i++){
            if(bills[i] == 5){
                dp[0]++;
            } else if(bills[i] == 10){
                // means 10
                if(!dp[0]) return false;
                dp[0]--;
                dp[1]++;
            } else{
                // means 20
                // either 1 10 or 1 5
                if(dp[0]>=1 && dp[1]>=1){
                    dp[0]--;
                    dp[1]--;
                }else if(dp[0]>=3){
                    dp[0]-=3;
                } else{
                    return false;
                }
            }
        }
        return true;
    }
};