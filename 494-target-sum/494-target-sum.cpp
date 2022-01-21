class Solution {
public:
    int totalway(vector<int>& nums, int target,int index){
        if(target==0 && index==nums.size() ){
            return 1;
        }
        if(index>=nums.size() && target!=0){
            return 0;
        }
        int pos=totalway(nums,target-nums[index],index+1);
        int neg=totalway(nums,target+nums[index],index+1);
        return pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return totalway(nums,target,0);
        
    }
};