class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        int n=nums.size();
        unordered_map<int,int>mymap;
        int count=0;
        
        
        for(int i=0;i<n;i++){
            mymap[nums[i]]++;
        }
        
        if(k==0){
            for(auto x:mymap){
                if(x.second>1){
                    count++;
                }
            }
             return count;
        }
    
        for(auto x:mymap){
            if(mymap.count(x.first-k)){
                count++;
            }
        }
        return count;
    }
};