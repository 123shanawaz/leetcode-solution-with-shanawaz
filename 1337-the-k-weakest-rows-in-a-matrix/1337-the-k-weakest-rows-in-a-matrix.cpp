class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>>maxh; // sum, index pair
        vector<int>ans;
        for(int i=0;i<mat.size();i++){
            int sum=0;
            for(int j=0;j<mat[i].size();j++){
                sum+=mat[i][j];
            }
            maxh.push({sum,i});
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        while(maxh.size()>0){
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};