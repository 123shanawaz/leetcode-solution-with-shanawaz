class Solution {
public:
    int dp[10001];
    bool jump(vector<int>& nums,int currentidx){
        if(currentidx>=nums.size()-1){
            return true;
        }
        if(dp[currentidx]!=-1){
            return dp[currentidx];
        }
       int currentjump=nums[currentidx];
        bool ans=false;
        for(int i=1;i<=currentjump;i++){
            bool ans2=jump(nums,currentidx+i);
            ans= ans||ans2;
            if(ans){
                
                return  dp[currentidx]=ans;
            }
        }
        return dp[currentidx]=false;
        
    }
    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return jump(nums,0);
        
    }
};