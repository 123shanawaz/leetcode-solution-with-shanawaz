class Solution {
public:

//int res;
int minimumEffortPath(vector<vector<int>>& ht) {
    int r=ht.size();
    int c=ht[0].size();
    int l=0,h=1e6;
    while(l<h)
    {
        int mid=l+(h-l)/2;
        vector<vector<bool>>vis(r , vector<bool>(c , false));
        if(solve(ht,0,0,r,c,ht[0][0],mid,vis))
        {
            h=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return h;
}
bool solve(vector<vector<int>>& ht,int sr,int sc,int r,int c,int pre,int mid, vector<vector<bool>>&vis)
{
            if(sr<0 || sc<0 || sr>=r || sc>=c || vis[sr][sc] == true)
             return false;
            if(sr==r-1 && sc==c-1 && abs(ht[sr][sc] - pre ) <= mid)
             return true ;
             if(abs(ht[sr][sc] - pre)> mid)return false;
            vis[sr][sc] = true;
            return solve(ht , sr+1 , sc , r,c,ht[sr][sc] , mid,vis)||
                   solve(ht , sr-1 , sc , r,c,ht[sr][sc] , mid,vis)||
                   solve(ht , sr , sc-1 , r,c,ht[sr][sc] , mid,vis)||
                   solve(ht , sr , sc+1 , r,c,ht[sr][sc] , mid,vis);
           // return false;   
}
};