class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>visited(rooms.size(), false);
        // mein int daal rha hu
        queue<int> pq;
        pq.push(0);

        while(pq.size()){
            int n = pq.size();
            for(int i = 0; i< n; i++){
                auto temp = pq.front();
                pq.pop();
                visited[temp] = true;
                for(auto x: rooms[temp]){
                    if(!visited[x]){
                        pq.push(x);
                    }
                }
            }
        }
        for(auto x: visited) if(!x) return false;
        return true;

    }
};