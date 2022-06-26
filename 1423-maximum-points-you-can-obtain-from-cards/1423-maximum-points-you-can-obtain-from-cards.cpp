class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int front=k-1,back=nums.size()-1;
        int sum=0,maxi=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        maxi=sum;
        while(front>=0 && front<back){
            sum+=nums[back]-nums[front];
            maxi=max(maxi,sum);
            back--; front--;
        }
        return maxi;
    }
};