class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    bool ans=false;
        
        int n = matrix[0].size() - 1 ; int m =  matrix.size() - 1;
        int i = 0 , j = n;
        while(i >= 0 && j >= 0 && j <= n && i <= m){
            if(matrix[i][j] == target){ ans = true; break;}
            else if(matrix[i][j] > target)
               j--;
            else
                i++;
        }
        return ans;
        
    }
};