class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int,int>mp;
        return total(0,n,mp);
    }
    private: int total(int currstair,int target,unordered_map<int,int>&mp){
        if(currstair>target){
            return 0;
        }
        if(currstair==target){
            return 1;
        }
        int currkey=currstair;
        if(mp.find(currkey)!=mp.end()){
            return mp[currkey];
        }
        int onejump=total(currstair+1,target,mp);
        int twojump=total(currstair+2,target,mp);
        mp[currkey] =onejump+twojump;
        return mp[currkey];
    }
};