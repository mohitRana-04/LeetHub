class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        vector<int> row;
        if (m * n != original.size()) return {};
        for(int i = 0; i< original.size(); i++){
            int takeind = i+1;
            if (takeind%n == 0){
                row.push_back(original[i]);
                ans.push_back(row);
                row = {};
                
            } else{
                row.push_back(original[i]);
            }
        }
        return ans;
    }
};