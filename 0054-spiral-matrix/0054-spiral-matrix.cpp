class Solution {
public:
    vector<int> ans;

    void helper(vector<vector<int>>& matrix, vector<vector<int>>& visited, int i, int j, int n, int m){
        if(i<0 || j< 0 || i>=n || j>=m || visited[i][j]) return;

        visited[i][j] = 1;
        ans.push_back(matrix[i][j]);

        if(i<=j+1){
            helper(matrix, visited, i, j+1, n, m);
        }
        helper(matrix, visited, i+1, j, n, m);
        helper(matrix, visited, i, j-1, n, m);
        helper(matrix, visited, i-1, j, n, m);

    }

        vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        helper(matrix, visited, 0, 0, n, m);

        return ans;
    }
};