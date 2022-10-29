class Solution {
public:
   int earliestFullBloom(vector<int>& pT, vector<int>& gT) 
{
    vector <pair<int,int>> vp;
    for(int i=0; i<pT.size(); i++)
        vp.push_back({gT[i],pT[i]});   //{growTime, plantTime}
    
    sort(vp.begin(), vp.end());   //sorting by growTime
    
    int ans=  0, planting = 0;
	
    for(int i=vp.size()-1; i>=0; i--)
    {
        planting += vp[i].second;
        ans = max(ans, planting + vp[i].first);
    }
    
    return ans;   
}
};