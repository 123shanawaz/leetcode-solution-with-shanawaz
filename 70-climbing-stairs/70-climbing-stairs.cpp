class Solution {
public:
    int totalway(int currstair,int target,unordered_map<int,int>&mp){
        if(currstair==target){
            return 1;
        }
        if(currstair>target){
            return 0;
        }
        int currkey=currstair;
        if(mp.find(currkey)!=mp.end()){
            return mp[currkey];
        }
        int onejump=totalway(currstair+1,target,mp);
        int twojump=totalway(currstair+2,target,mp);
        mp[currkey]= onejump+twojump;
        return mp[currkey];
    }
    int climbStairs(int n){
        unordered_map<int ,int>mp;
       return totalway(0,n,mp);
    }
};