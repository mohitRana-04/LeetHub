class Solution {
public:

    string losingPlayer(int x, int y) {

        // int sum = 115;
        
        // x+4y
        int counter = 0;
        while(x){
            if(y>=4){
                counter++;
                y=y-4;
            } else{
                break;
            }
            x--;
        }

        if(counter%2==1) return "Alice";
        return "Bob";

    }
};