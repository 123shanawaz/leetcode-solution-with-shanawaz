class Solution {
public:
    int mp[10001];
    int totalWays(vector<int>&nums, int currentIndex,int target){
        if(target==0){
            return 1;
        }
        if(currentIndex >= nums.size()|| target<=0){
          return 0;
        }
      
        if(mp[target]!=-1){
            return mp[target];
        }
        int pick =  totalWays(nums,0, target - nums[currentIndex]);
        int notPick = totalWays(nums, currentIndex+1, target);
        mp[target] = pick+notPick;
        return mp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(mp,-1,sizeof(mp));
        return totalWays(nums,0,target);
    }
};
