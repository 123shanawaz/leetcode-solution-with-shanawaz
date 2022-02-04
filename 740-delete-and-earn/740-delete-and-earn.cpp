class Solution {
public:
    int dp[10001];
    int maxpoint(vector<int>& nums,int currentidx){
        if(currentidx>=nums.size()){
            return 0;
        }
        if(dp[currentidx]!=-1){
            return dp[currentidx];
        }
        int earn=0;
        earn=maxpoint(nums,currentidx+2)+nums[currentidx];
        int notearn=maxpoint(nums,currentidx+1);
        dp[currentidx]=max(earn,notearn);
        return dp[currentidx];
    }
    int deleteAndEarn(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        vector<int> a(10001,0);
        for(auto num : nums) a[num] += num;
        return maxpoint(a,0);
        
    }
};