class Solution {
public:
    int minSwaps(string s) {
        int open = 0;
        for(auto x: s){
            if( x == ']'){
                if(open == 0) open++;
                else open--;
            } else{
                open++;
            }
        }
        return (open+1)/2;
    }
};