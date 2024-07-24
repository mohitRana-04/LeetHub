class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<vector<int>>& graph, int start, int end, vector<int> res){
        res.push_back(start);
        if(start == end){
            ans.push_back(res);
        }else{
            for(auto x: graph[start]){
            
                solve(graph, x, end, res);
            }
        }
        
        res.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> res;
        solve(graph, 0, graph.size()-1, res);
        return ans;

    }
};