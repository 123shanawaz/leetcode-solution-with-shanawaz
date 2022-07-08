class Solution {
public:

    int minCost(vector<int>& painted, vector<vector<int>>& costs, int houses, int colors, int target) {
        // write your code here
        
        if(!houses) return 0;
        int dp[houses][target+1][colors+1];
        int ans=1e8;
        
        for(int i=0;i<houses;i++)
            for(int t=0;t<=target;t++)
                for(int k=0;k<=colors;k++)
                        dp[i][t][k] = 1e8;
        
        for(int k=1;k<=colors;k++)
            if(!painted[0])
                dp[0][1][k] = costs[0][k-1];
        
        if(painted[0])
            dp[0][1][painted[0]] = 0;
            
        for(int i=1;i<houses;i++){
            for(int t=1;t<=target;t++){
                
                if(painted[i]){
                    int currColor=painted[i];
                    dp[i][t][currColor] = dp[i-1][t][currColor];

                    for(int prevColor=1;prevColor<=colors;prevColor++){
                        if(prevColor!=currColor)
                            dp[i][t][currColor] = min(dp[i][t][currColor],dp[i-1][t-1][prevColor]);
                    }
                }
                else{
                    for(int currColor=1;currColor<=colors;currColor++){
                        dp[i][t][currColor] =INT_MAX;

                        for(int prevColor=1;prevColor<=colors;prevColor++){
                            if(currColor==prevColor)
                                dp[i][t][currColor] = min(dp[i][t][currColor],costs[i][currColor-1]+dp[i-1][t][prevColor]);
                            else
                                dp[i][t][currColor] = min(dp[i][t][currColor],costs[i][currColor-1]+dp[i-1][t-1][prevColor]);
                        }
                    }
                }
            }
        }
        
        
        for(int k=1;k<=colors;k++)
            ans=min(ans,dp[houses-1][target][k]);
        
        
        return ans>=1e8?-1:ans;
    }
};
