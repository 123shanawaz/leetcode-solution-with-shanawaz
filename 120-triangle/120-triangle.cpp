class Solution {
public:
   int solve(int i, int j, int n, vector<vector<int>>&triangle, unordered_map<string,int>&dp) {
		if(i == n - 1)
			return triangle[i][j];
		
       string currkey=to_string(i)+"_"+to_string(j);
       if(dp.find(currkey)!=dp.end()){
           return dp[currkey];
       }
		int bottom = triangle[i][j] + solve(i+1, j, n, triangle, dp);
		int  bottom_right = triangle[i][j] + solve(i+1, j+1, n, triangle, dp);
		 dp[currkey] = min(bottom, bottom_right);
       return dp[currkey];
	}
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		unordered_map<string,int>dp;
		return solve(0, 0, n, triangle, dp);
	}
};