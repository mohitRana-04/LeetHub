class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord.size() != endWord.size()) return 0;

        unordered_map<string, int> mp;
        unordered_map<string, int> visited;
        for(auto x: wordList) mp[x]++;
        
        int cnt = 1;
        queue<string> pq;
        pq.push(beginWord);
        visited[beginWord]++;

        while(pq.size()){
            int n = pq.size();
            for(int i = 0; i< n; i++){
                string temp = pq.front();
                pq.pop();
                if(temp == endWord) return cnt;
                for(char ch= 'a'; ch<='z'; ch++){
                    // char c 
                    char c = ch;
                    for(int k = 0; k< temp.size(); k++ ){
                        char ran = temp[k];
                        temp[k] = ch;

                        if(mp[temp] && !visited[temp]){
                            pq.push(temp);
                            visited[temp]++;
                        }

                        temp[k] = ran;
                    }
                }
                 
            }
            cnt++;
        }
        return 0;

    }
};