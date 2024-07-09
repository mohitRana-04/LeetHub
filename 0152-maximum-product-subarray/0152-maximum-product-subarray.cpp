class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // take product from starting as well from backward
        
        double p1 = 1, mul1 = nums[0], p2 =1, mul2 = nums[nums.size()-1];
        

        for(int i = 0; i< nums.size(); i++){
            if(p1 == 0){
                p1 = 1;
            }
            p1 = p1*nums[i];
            mul1 = max(mul1, p1);
        }

        for(int i = nums.size()-1; i>=0; i--){
            if(p2 == 0){
                p2 = 1;
            }
            p2 = p2*nums[i];
            mul2 = max(mul2, p2);
        }
        return int(max(mul1, mul2));

    }
};