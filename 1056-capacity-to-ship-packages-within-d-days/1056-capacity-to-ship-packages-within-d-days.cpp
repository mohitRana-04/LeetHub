class Solution {
public:

    int solve(int mid, vector<int> weights){
        int cap = 0, day = 1;
        for(auto x: weights){
            cap = cap+x;
            if(cap>mid){
                day++;
                cap = x;
            }
        }
       
        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int r = 0, l = 0;
        for(auto x: weights){
            r+=x;
            l = max(l,x);
        } 
        

        while(l<r){
            int mid = l+(r-l)/2;
            if(solve(mid,weights)<=days){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};