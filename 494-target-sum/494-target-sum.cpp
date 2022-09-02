class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return totalway(nums,0,target);
        
    }
    private: int totalway(vector<int>& nums,int currindex, int target){
        if(currindex==nums.size() && target==0){
            return 1;
        }
        if(currindex==nums.size() && target!=0){
            return 0;
        }
        int pos=totalway(nums,currindex+1,target+nums[currindex]);
        int nig=totalway(nums,currindex+1,target-nums[currindex]);
        return pos+nig;
    }
};