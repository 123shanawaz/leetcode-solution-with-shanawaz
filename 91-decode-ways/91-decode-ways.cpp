class Solution
{
public:
	int numDecodings(string s)
	{
        unordered_map<int,int>mp;
		if (s.empty())
			return 0;
		return rec(0, s,mp);
	}
	int rec(int p, string &s,unordered_map<int,int>&mp)
	{

		int n = s.size();

		if (p == n)
			return 1;

		if (s[p] == '0')
			return 0;
        int currkey=p;
        if(mp.find(currkey)!=mp.end()){
            return mp[currkey];
        }

		int res = rec(p + 1, s,mp);

		if (p < n - 1 && (s[p] == '1' || (s[p] == '2' && s[p + 1] < '7')))
			res += rec(p + 2, s,mp);

		mp[currkey]=res;
        return mp[currkey];
	}
};