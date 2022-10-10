//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int newColor) {
        if(grid[sr][sc]==newColor) return grid;
        int m = grid.size();
        int n = grid[0].size();
        int color = grid[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int curr_row = it.first;
            int curr_col = it.second;
            if(curr_row<0 || curr_row>=m || curr_col<0 || curr_col>=n || grid[curr_row][curr_col]!=color)
                continue;
            grid[curr_row][curr_col] = newColor;
            q.push({curr_row-1,curr_col});
             q.push({curr_row,curr_col+1});
             q.push({curr_row+1,curr_col});
             q.push({curr_row,curr_col-1});
        }
        return grid;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends