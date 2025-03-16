class Solution {
public:
// top down
    int solve(vector<int> nums, int ind){
        if(ind >= nums.size()) return 0;
        if(ind == nums.size()-1) return nums[nums.size()-1];

        int take = nums[ind]+solve(nums, ind+2);
        int nottake = solve(nums, ind+1);
        return max(take, nottake);
    }
    int rob(vector<int>& nums) {
        
        int dp[401];
        memset(dp, 0, sizeof(dp));

        dp[0]= 0;
        dp[1] = nums[0];

        for(int i = 2; i<= nums.size(); i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }
        return dp[nums.size()];
        
    }
};