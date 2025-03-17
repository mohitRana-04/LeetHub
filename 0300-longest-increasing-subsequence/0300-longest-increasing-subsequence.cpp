class Solution {
public:
    int dp[2501][2501];
    int solve(vector<int> &nums, int ind, int prev){
        if(ind>=nums.size()) return 0;
        if(prev != -1 && dp[ind][prev] != -1) return dp[ind][prev];

        int take = 0, nottake = 0;
        if(prev == -1 || nums[ind]>nums[prev]){
            take =  1+ solve(nums, ind+1, ind);
        } 
        nottake =  solve(nums, ind+1, prev);
        

        if(prev!= -1){
            dp[ind][prev] = max(take, nottake);
        }   
        return max(take, nottake);
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, -1);
    }
};