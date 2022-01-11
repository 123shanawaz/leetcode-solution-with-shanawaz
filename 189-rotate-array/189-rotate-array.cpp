class Solution {
public:
    
    void reverse(vector<int>& nums,int start,int end){
        while(start<=end){
            int temp=nums[start];
            nums[start]=nums[end];
            nums[end]=temp;
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
      /*  
        2 3 4 5 1// k=-1
        1 2 3 4 5 //
        5 1 2 3 4 //1 r
        4 5 1 2 3 //2 r
        3 4 5 1 2 //3 r
        2 3 4 5 1//4 r
        1 2 3 4  5 // r
        */    
            
        if(k<0){
            k=k+nums.size();
        }
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);
        
    }
};