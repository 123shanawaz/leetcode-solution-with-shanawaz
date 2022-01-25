class Solution {
public:
    int path(vector<vector<int>>& obstacleGrid ,int m,int n,int i,int j,unordered_map<string,int>&mp){
        if(i>=m||j>=n){
            return 0;
        }
        if(obstacleGrid[i][j]==1){
            return 0;
        }
        if(i==m-1&&j==n-1){
            return 1;
        }
        string currentkey=to_string(i)+"_"+to_string(j);
        if(mp.find(currentkey)!=mp.end()){
            return mp[currentkey];
        }
        int right=path(obstacleGrid,m,n,i,j+1,mp);
        int left=path(obstacleGrid,m,n,i+1,j,mp);
        mp[currentkey]= right+left;
        return mp[currentkey];
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        unordered_map<string,int>mp;
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        return path(obstacleGrid,m,n,0,0,mp);
        
    }
};