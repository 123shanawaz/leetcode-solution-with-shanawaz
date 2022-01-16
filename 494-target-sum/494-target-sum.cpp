class Solution {
public:
    int targetsum(vector<int>& nums, int target,int currentidx,unordered_map<string,int>&mp){
        if(currentidx>=nums.size()&&target!=0){
            return 0;
        }
        if(target==0&&currentidx>=nums.size()){
            return 1;
        }
        string currentkey=to_string(currentidx)+"_"+to_string(target);
        if(mp.find(currentkey)!=mp.end()){
            return mp[currentkey];
        }
        
          int pic=targetsum(nums,target-nums[currentidx],currentidx+1,mp);
          int notpic=targetsum(nums,target+nums[currentidx],currentidx+1,mp);
        mp[currentkey]= pic+notpic;
        return mp[currentkey];
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,int>mp;
        return targetsum(nums,target,0,mp);
        
    }
};