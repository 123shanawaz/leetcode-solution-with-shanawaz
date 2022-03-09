class Solution {
public:
    int mincost(vector<int>&cost,int curridx,unordered_map<int,int>&mp){
        if(curridx==cost.size()){
            return 0;
        }
        if(curridx>cost.size()){
            return 10001;
            
        }
        int currkey=curridx;
        if(mp.find(currkey)!=mp.end()){
            return mp[currkey];
        }
         int onejump=cost[curridx]+mincost(cost,curridx+1,mp);
         int twojump=cost[curridx]+mincost(cost,curridx+2,mp);
        mp[currkey]= min(onejump,twojump);
        return mp[currkey];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int,int>mp;
        int a=mincost(cost,0,mp);
        int b=mincost(cost,1,mp);
        return min(a,b);
    }
};