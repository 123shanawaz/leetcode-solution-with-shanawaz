class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int start=0;
        int end=n*m-1;
        int mid=start+(end-start)/2;
        while(start<=end){
            int element=matrix[mid/m][mid%m];
            if(element==target){
                return true;
            }
            else if(element<target){
                start=mid+1;
            }
            else {
                end=mid-1;
            }
            mid=start+(end-start)/2;
        }
        return false;
    }
};