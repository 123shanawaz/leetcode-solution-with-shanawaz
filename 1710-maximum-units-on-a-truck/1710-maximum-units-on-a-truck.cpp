class Solution {
public:
    bool static comparator(vector<int> &x,vector<int> &y){
        return (x[1]>y[1]);
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comparator);
        int ans=0; //total units
		
        for(int i=0;i<boxTypes.size();i++){
            int box_count=min(boxTypes[i][0],truckSize);
            ans+=box_count*boxTypes[i][1];
            truckSize-=box_count;
            if(truckSize==0)
                break;
        }
        return ans;
    }
};