class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>vis(n,false);
        queue<int>q;
       
        q.push(0);
         vis[0]=true;
        while(!q.empty()){
            int it=q.front();
            q.pop();
            for(auto key:rooms[it]){
                if(!vis[key]){
                    vis[key]=true;
                    q.push(key);
                }
            }
        }
        for(auto x:vis){
            if(x==false) return false;
        }
       return true;
    }
};