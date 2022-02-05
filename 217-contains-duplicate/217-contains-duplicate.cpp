class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
         unordered_map<int, int> amap;
         for(auto x: nums)
                 amap[x]++;
           for(auto y: amap){
                     if(y.second>1)
                            return true;
             }
         return false;
          }
        
        
    
};