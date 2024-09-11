class Solution {
public:
    int minBitFlips(int start, int goal) {
        int step = 0;
        while(start || goal){
            int rem1 = start%2;
            start/=2;
            int rem2 = goal%2;
            goal/=2;
            if(rem1 != rem2) step++;
        }
        return step;
    }
};