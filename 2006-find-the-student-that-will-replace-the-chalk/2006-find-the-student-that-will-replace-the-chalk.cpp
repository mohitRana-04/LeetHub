class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(auto x: chalk){
            sum+=x;
        }

        int rem = k%sum;
        if(rem == 0) return 0;
        for(int i = 0; i< chalk.size(); i++){
            if(chalk[i]<=rem) rem -=chalk[i];
            else return i;
        }
        return 0;
    }
};