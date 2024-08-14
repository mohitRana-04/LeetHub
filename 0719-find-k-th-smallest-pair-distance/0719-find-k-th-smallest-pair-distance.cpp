class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int mx = INT_MIN;
        for(auto x: nums) mx = max(mx, x);
        int dp[mx+1];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i< nums.size(); i++){
            for(int j = i+1; j< nums.size(); j++){
                int d = abs(nums[i]-nums[j]);
                dp[d]++;
            }
        }

        for(int i = 0; i< mx+1; i++){
            k-=dp[i];
            if(k<=0){
                return i;
            } 
            
        }
        return -1;

    }
};