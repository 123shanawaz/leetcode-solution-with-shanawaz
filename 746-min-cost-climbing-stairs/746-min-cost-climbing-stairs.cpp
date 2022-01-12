class Solution {
public:
    int mincost(int current,int n,vector<int>& cost,unordered_map<int,int> &mp){
      
      // when we reach the last index/top, return 0, 0 is the cost of the top
      if(current==n)  return 0;
      // when we reach > the last index/top, return INT_MAX/cost.length
      if(current>n)   return INT_MAX;
      
      // take the changing variable as the key
      int currentkey = current;
      // check if the key is the present in the map or not
      if(mp.find(currentkey)!=mp.end()){
        return mp[currentkey];
      }
      
      // either we can take 1 step, current+1
      int one_step = mincost(current+1,n,cost,mp);
      // or we can take 2 step, current+2
      int two_step = mincost(current+2,n,cost,mp);
      
      // take the minimum of jump + cost of the current as mp[key]
      mp[currentkey] = cost[current]+min(one_step,two_step);
      return mp[currentkey];
    }
    int minCostClimbingStairs(vector<int>& cost){
        int n = cost.size();
        unordered_map<int,int> mp;
      
        // we can take jump from either 0 or 1
        // so calculate the minimum of 0 and 1
        return min(mincost(0,n,cost,mp),mincost(1,n,cost,mp));
    }
};
