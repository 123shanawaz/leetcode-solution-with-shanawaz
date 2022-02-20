class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        if (a[0] != b[0]){
            return a[0] < b[0];
        }else{
            return a[1] > b[1];
        }
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // - Sort the intervals in increasing order of starting point
        // - If starting points are same, in decreasing order of ending point
        sort(intervals.begin(), intervals.end(), comp);
        
        int _max = INT_MIN;
        int count = 0;
        
        // - Compare the ending points in the sorted intervals
		
        // - If at any index the ending point is less than the current maximum ending point
        //   that interval is the included one 
		//   (remember the starting point of the current is already greater than that
		//   of all the previous intervals, so now when the ending point is lesser than the current max ending point
		//   it means that interval is included in atleast one of the previous intervals)
		
        // - Count the included ones and return size()-count
		
		// Note: If the starting index are equal, we sorted according to decreasing ending index so that it can be
		// counted too as an included one
		
        for (int i = 0; i<intervals.size(); i++){
            if (intervals[i][1] <= _max){
                count ++;
            }else{
                _max = intervals[i][1];
            }
        }
        return intervals.size()-count;
    }
};