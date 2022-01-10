class Solution {
public:
    int totalways(int targetstair,int currentstair,unordered_map<int,int>&mp){
        if(currentstair==targetstair){
            return 1;
        }
        if(currentstair>targetstair){
            return 0;
        }
            int currentkey=currentstair;
            if(mp.find(currentkey)!=mp.end()){
                return mp[currentkey];
            }
        
        int onejump=totalways(targetstair, currentstair+1,mp);
       int twojump=  totalways( targetstair, currentstair+2,mp);
        mp[currentkey]= onejump+twojump;
        return mp[currentkey];
    }
    int climbStairs(int n) {
        unordered_map<int,int>mp;
        return totalways(n,0,mp);
    }
};