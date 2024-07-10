class Solution {
public:
    int jump(vector<int>& nums) {
        int reach = 0, end = 0;
        int ans = 0;

        for(int i = 0; i< nums.size()-1; i++){
            reach = max(reach, nums[i]+i);
            if(i == end){
                ans++;
                end = reach;
            }
        }
        return ans;

    }
};