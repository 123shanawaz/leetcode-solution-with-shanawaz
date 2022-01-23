class Solution {
public:
    int dp[10001];
    int minjump(vector<int>& nums,int currentidx){
        if(currentidx>=nums.size()-1){
            return 0;
        }
        if(dp[currentidx]!=-1){
            return dp[currentidx];
        }
       int currentjump=nums[currentidx];
        int ans=10001;
        for(int i=1;i<=currentjump;i++){
            int ans2=1+minjump(nums,currentidx+i);
            ans= min(ans,ans2);
            
        }
        return dp[currentidx]=ans;
        
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return minjump(nums,0);
        
    }
};