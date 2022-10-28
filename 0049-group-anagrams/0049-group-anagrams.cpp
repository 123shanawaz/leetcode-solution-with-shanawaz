class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        vector<vector<string>> ans;
        for(int i=0; i<strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            m[s].push_back(strs[i]);
        }
        for(auto it1=m.begin(); it1!=m.end(); it1++)
            ans.push_back(it1->second);
        return ans;
    }
};