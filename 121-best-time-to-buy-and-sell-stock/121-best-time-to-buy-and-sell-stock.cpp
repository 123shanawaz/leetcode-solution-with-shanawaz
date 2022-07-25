class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxR=prices[n-1];
      int  max_profit=0;
        for(int i=n-2;i>=0;i--){
            maxR=max(maxR,prices[i]);
                max_profit=max( max_profit,maxR-prices[i]);
            
        }
        return max_profit;
        
    }
};