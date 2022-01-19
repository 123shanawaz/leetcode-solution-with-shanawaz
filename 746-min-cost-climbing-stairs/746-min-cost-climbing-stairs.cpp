class Solution {
public:
    
   int mincost(vector<int>& cost,int currentidx,unordered_map<int,int>&mp){
       if(cost.size()==currentidx){
           return 0;
   }
    if(currentidx>cost.size()){
        return INT_MAX;
    }
       int currentkey=currentidx;
       if(mp.find(currentkey)!=mp.end()){
           return mp[currentkey];
       }
    int onejump=mincost(cost,currentidx+1,mp);
     int twojump=mincost(cost,currentidx+2,mp);
       mp[currentkey]=min(onejump,twojump)+cost[currentidx];
       return mp[currentkey];
   }
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int,int>mp;
        int a=mincost(cost,0,mp);
        int b=mincost(cost,1,mp);
        return min(a,b);
    }
};