class Solution {
public:
   int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<pair<int,int>> a,b;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1) a.push_back({i,j});
                if(img2[i][j]==1) b.push_back({i,j});
            }
        }
        
        int ans=0;
        map <pair<int,int>,int> mp;
        for(auto [i1,j1] : a){
            for(auto [i2,j2] : b){
                mp[{i2-i1,j2-j1}]++;
                ans = max(ans,mp[{i2-i1,j2-j1}]);
            }
        }
        return ans;
    }
};