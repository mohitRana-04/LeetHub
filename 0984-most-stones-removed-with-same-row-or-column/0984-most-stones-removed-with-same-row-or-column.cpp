class Solution {
public:

    void dfs(vector<vector<int>>& stones, int index, vector<bool> &visited){
        visited[index] = true;
        for(int i = 0; i< stones.size(); i++){
            int row = stones[index][0];
            int col = stones[index][1];
            if((stones[i][0] == row || stones[i][1] == col) && !visited[i]){
                dfs(stones, i, visited);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int ans = 0;
        vector<bool> visited (stones.size(), 0);

        for(int i = 0; i< stones.size(); i++){
            if(!visited[i]){
                dfs(stones, i, visited);
                ans++;
            }
        }
        return stones.size()- ans;
    }
};