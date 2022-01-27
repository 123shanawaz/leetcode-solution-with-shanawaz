class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int min=nums[0];
        int max=nums[nums.size()-1];
        int count=0;
        for(auto it:nums){
            if(it>min&&it<max)
                count++;
        }
        return count;
        
    }
};