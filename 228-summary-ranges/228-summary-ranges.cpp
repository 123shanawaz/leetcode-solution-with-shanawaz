class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        	if (!nums.size()) {
		return {};
	}
	if (nums.size() == 1) {
		return {to_string(nums[0])};
	}
	vector<string> res;
	for(int i = 0; i < nums.size(); i++) {
		if (!res.size()) {
			res.push_back(to_string(nums[i]));
		}
		if ((i > 0 && nums[i] != nums[i - 1] + 1)) {
			if (res.back() != to_string(nums[i - 1])) {
				res.back() = res.back() + "->" + to_string(nums[i - 1]);
			}
			res.push_back(to_string(nums[i]));
		} else if (i == nums.size() - 1) {
			res.back() = res.back() + "->" + to_string(nums[i]);
		}
	}
	return res;
}

    
};