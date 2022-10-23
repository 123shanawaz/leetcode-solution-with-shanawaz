class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int initialSum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        unordered_map <int,int> mp;
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        vector <int> v(2);
        for(auto i:mp)
            if(i.second==2)
                v[0]=i.first;
        v[1]=n*(n+1)/2-(initialSum-v[0]);
        return v;
    }
};