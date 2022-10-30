class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<int> dir={0,-1,0,1,0};
        int n=grid.size(), m=grid[0].size();
        queue<pair<pair<int,int>, pair<int,int>>> q; 
        vector<vector<vector<bool>>> isVis(n, vector<vector<bool>>(m, vector<bool>(k+1,0)));
        q.push({{0,0},{0,0}});
        while(q.size()){
            auto info=q.front(); 
            q.pop();
            int i=info.first.first, j=info.first.second, count=info.second.first, dist=info.second.second;
            if(count>k || i<0 || j<0 || i>=n || j>=m || isVis[i][j][count])
                continue;
            isVis[i][j][count]=1;
            if(i==n-1 && j==m-1) 
                return dist;
            for(int d=0; d<4; d++){
                int ni=i+dir[d], nj=dir[d+1]+j;
                if(ni<0 || nj<0 || ni>=n || nj>=m ) 
                    continue;
                if(grid[ni][nj]){
                    if(count>k || isVis[ni][nj][count+1])
                        continue;
                    q.push({{ni,nj},{count+1,dist+1}});
                }
                else{
                    if(count>k || isVis[ni][nj][count])
                        continue;
                    q.push({{ni,nj},{count,dist+1}});
                }
            }
        }
        return -1;
    }
};