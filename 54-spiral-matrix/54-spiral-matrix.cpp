class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int left=0;
        int right=m-1;
        int top=0;
        int bottom=n-1;
        int direction=1;
        vector<int>ans;
        while(left<=right && top<=bottom){
            if(direction==1){
            for(int index=left;index<=right;index++)
                ans.push_back(matrix[top][index]);
                top++;
                direction=2;
            
            }
            else if(direction==2){
                for(int index=top;index<=bottom;index++)
                ans.push_back(matrix[index][right]);
                right--;
                direction=3;
            
            }
                else if(direction==3){
                    for(int index=right;index>=left;index--)
                ans.push_back(matrix[bottom][index]);
                bottom--;
                direction=4;
            
                }
            else if(direction==4){
                for(int index=bottom;index>=top;index--)
                ans.push_back(matrix[index][left]);
                left++;
                direction=1;
            
            }
                
            
        }
    return ans;
        
    }
};