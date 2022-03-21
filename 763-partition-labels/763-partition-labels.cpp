class Solution {
public:
    vector<int> partitionLabels(string s) {
        int arr[26];
        vector<int>ans;
        memset(arr,0,sizeof(arr));
        for(int i = 0; i<s.size();i++){
            arr[s[i]-'a']++;
        }
        int l = 0;
        int r = 0;
        // this is temp array where we store values from l to r. 
        int temp[26];
        memset(temp, 0, sizeof(temp));
        while(r<s.size()){
            temp[s[r]-'a']++;
            int count = 0;
            // if any element exist in temp array and it doesnt exist in main array equally,
            //then we have to traverse forward till all the elements in temp array are 
            //in exact frequency in main array. then we append (r-l+1) to answer. 
            for(int i = 0; i<26;i++){
                if(temp[i]){
                    if(temp[i] != arr[i]){
                        count++;
                    }
                }
            }
			// it means all the elements in temp array are present in same frequency in main array. 
            if(count==0){
                ans.push_back(r-l+1);
                r++;
                l = r;
                memset(temp,0, sizeof(temp));
                // so that we have to process less characters. 
            }
			//it means atleast 1 element in temp array will occurs again in string.
            else r++;
        }
        return ans;
    }
};