class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int dir[2051] = {0};
        for(auto x: logs){
            dir[x[0]]++; // births
            dir[x[1]]--; // deaths
        }

        for(int i = 1; i< 2051; i++){
            dir[i] = dir[i] + dir[i-1];
        }
        
        int maxi = INT_MIN;
        int res = 0;
        for(int i = 0; i< 2051; i++){
            if(dir[i]>maxi) maxi = max(maxi, dir[i]), res = i;
        }
        return res;
    }
};