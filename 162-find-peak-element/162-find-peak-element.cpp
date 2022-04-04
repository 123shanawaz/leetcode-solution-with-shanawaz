class Solution {
public:
    int findPeakElement(const vector<int> &num) 
    {
        int low = 0;
        int high = num.size()-1;
        
        while(low <high)
        {
            int mid1 = (low+high)/2;
            
            if(num[mid1] < num[mid1+1])
                low = mid1+1;
            else
                high = mid1;
        }
        return low;
    }
};