class Solution {
public:
    char kthCharacter(int k) {
        string res = "a";
        while(res.size()<k){
            string temp = "";
            for(int i = 0; i< res.size(); i++){
                if(res[i] == 'z') temp.push_back('a');
                else temp.push_back(res[i]+1);
            }
            res+=temp;
        }
        return res[k-1];
    }
};