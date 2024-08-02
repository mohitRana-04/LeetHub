class Solution {
public:

    int solve(vector<int> weights, int days, int mid){
        int cnt = 1;
        int sum = 0;
        for(auto x: weights){
            sum = sum+x;
            if(sum>mid){
                sum = x;
                cnt++;
            }
            if(cnt>days) return false;
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxW = 0, sum = 0;
        for(auto x: weights){
            sum+=x;
            maxW = max(maxW, x);
        }

        while(maxW<sum){
            int mid = maxW+(sum-maxW)/2;
            if(solve(weights, days, mid)){
                sum = mid;
            } else{
                maxW = mid+1;
            }
        }
        return maxW;
    }
};