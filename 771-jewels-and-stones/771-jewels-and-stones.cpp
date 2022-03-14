class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
       int count=0;
        for(auto i:stones){
            for(auto j:jewels){
                if(i==j){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};