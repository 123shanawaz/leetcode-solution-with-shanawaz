class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        int maxLen = 0, sum = 0;
        for(int i=0;i<nums.size();i++) {
            sum += nums[i] == 0 ? -1 : 1;
            if(sum == 0) {   
                maxLen = max(maxLen, i+1);
            }
            if(m.find(sum) != m.end()) {
                maxLen = max(maxLen, i - m[sum]);
            } else {
                m[sum] = i;   
            }
        }
        return maxLen;
    }
};