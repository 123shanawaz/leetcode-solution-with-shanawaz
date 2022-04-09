class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
          priority_queue<pair<int, int>> pq;
        unordered_map<int, int>mp;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
             mp[nums[i]] += 1;      
        
         for (auto i : mp)
          pq.push(make_pair(i.second, i.first));
        
        for(int i=0;i<k;i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
             return res;
    }
};