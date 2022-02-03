class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>&D) {
        unordered_map<int, int>hm;
        
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                hm[A[i]+B[j]]++;
            }
        }
        
        int res = 0;
        for (int i = 0; i < C.size(); i++) {
            for (int j = 0; j < C.size(); j++) {
                if (hm.find(-C[i]-D[j]) != hm.end())
                    res += hm[-C[i]-D[j]];
            }
        }
        
        return res;
    }
};