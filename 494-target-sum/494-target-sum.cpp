class Solution {
public:
    int totalway(vector<int>& nums, int target,int index,unordered_map<string,int>&mp){
        if(target==0 && index==nums.size() ){
            return 1;
        }
        if(index>=nums.size() && target!=0){
            return 0;
        }
        string currentkey=to_string(index)+"_"+to_string(target);
        if(mp.find(currentkey)!=mp.end()){
            return mp[currentkey];
        }
        int pos=totalway(nums,target-nums[index],index+1,mp);
        int neg=totalway(nums,target+nums[index],index+1,mp);
        mp[currentkey]= pos+neg;
           return mp[currentkey];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,int>mp;
        return totalway(nums,target,0,mp);
        
    }
};