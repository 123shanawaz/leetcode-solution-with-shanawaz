class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), ans = 0;
        vector<vector<int>>dp(n1+1, vector<int>(n2+1, 0));
  
        for(int i = 1; i <= n1; i++)
            for(int j = 1; j <= n2; j++){
                if(nums1[i-1] == nums2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 0;
                ans = max(ans, dp[i][j]);
            }
        return ans;
    }
};