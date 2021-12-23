class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        int maximum;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
          maximum=max(nums[n-1]*nums[n-2]*nums[n-3],nums[0]*nums[1]*nums[n-1]);
        }
        return maximum;
    }
};