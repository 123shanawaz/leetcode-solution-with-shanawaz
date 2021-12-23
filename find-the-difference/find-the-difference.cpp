class Solution {
public:
    char findTheDifference(string s, string t) {
        char r=0;
        for(auto x:s){
            r^=x;
        }
        for(auto y:t){
            r^=y;
        }
        return r;
        
    }
};