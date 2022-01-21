class Solution {
public:
    int dp[101][100001];
    int diffcoin(vector<int>& coins, int amount,int currentidx){
        if(amount==0){
            return 0;
        }
        if(currentidx>=coins.size()){
            return 100001;
        }
        if(dp[currentidx][amount]!=-1){
            return dp[currentidx][amount];
        }
        
        int pic= 100001;
        if(coins[currentidx]<=amount){
            pic=1+diffcoin(coins,amount-coins[currentidx],currentidx);
        }
        int notpic=diffcoin(coins,amount,currentidx+1);
        dp[currentidx][amount]= min(pic,notpic);
        return dp[currentidx][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans= diffcoin(coins,amount,0);
        if(ans==100001){
            return -1;
        }
        return ans;
        
    }
};