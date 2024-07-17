class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) return true;
        int cnt =0;
        if(flowerbed.size() == 1){
            if(flowerbed[0] == 0 && n==1) return true;
            else return false;
        }
        if(!flowerbed[0] && !flowerbed[1]){
            flowerbed[0] = 1;
            cnt++;
        }

        int h = flowerbed.size()-1;
        if(!flowerbed[h] && !flowerbed[h-1]){
            flowerbed[h] = 1;
            cnt++;
        }

        for(int i = 1; i<flowerbed.size()-1; i++){
            if(!flowerbed[i] && !flowerbed[i+1] && !flowerbed[i-1] ){
                flowerbed[i] = 1;
                cnt++;
            }
        }
        return cnt >= n;

    }
};