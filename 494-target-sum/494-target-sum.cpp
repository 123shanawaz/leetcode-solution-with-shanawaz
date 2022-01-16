class Solution {
public:
    int targetsum(vector<int>& nums, int target,int currentidx){
        if(currentidx>=nums.size()&&target!=0){
            return 0;
        }
        if(target==0&&currentidx>=nums.size()){
            return 1;
        }
        
          int pic=targetsum(nums,target-nums[currentidx],currentidx+1);
          int notpic=targetsum(nums,target+nums[currentidx],currentidx+1);
        return pic+notpic;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return targetsum(nums,target,0);
        
    }
};