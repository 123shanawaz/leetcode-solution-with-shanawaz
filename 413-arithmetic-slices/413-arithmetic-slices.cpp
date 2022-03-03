class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        if(n<3)
            return 0;
        for(int i=0;i<n-1;i++){
            int diff = nums[i+1]-nums[i];
            for(int j=i+2;j<n;j++){
                if((nums[j]-nums[j-1])==diff){
                    count++;
                }
                else
                    break;
            }
        }
        return count;
        
    }
};