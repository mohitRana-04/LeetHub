class Solution {
public:

    int feasible(int mid, vector<int>& piles, int h){
        int count = 0;
        for(auto x: piles){
            count += ceil(double(x)/mid);
        }
        if(count>h) return false;
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;
        for(auto x: piles) r = max(r, x);

        while(l<r){
            int mid = l+(r-l)/2;
            if(feasible(mid, piles, h)){
                r =mid;
            } else{
                l = mid+1;
            }
        }
        return l;
    }
};