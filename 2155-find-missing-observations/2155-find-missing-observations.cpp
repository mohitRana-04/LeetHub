class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        for(auto x: rolls) sum+=x;

        int count = rolls.size()+n;
        mean = mean*count;
        mean = mean-sum;
        if(mean>n*6 || mean<n) return {};
        // return {mean};
        int dig = mean/n;
        int rem = mean%n;
        vector<int> res;
        for(int i = 0; i< n; i++){
            
            if(rem){
                res.push_back(dig+1);
                rem--;
            } else{
                res.push_back(dig);
            }
            
            


           
        } 
        return res;
    }
};