class Solution {
public:
    vector<int> separateDigits(vector<int> &nums)
    {
        vector<int> ans;
        for(int num:nums)
        {
            string s=to_string(num);
            for(char ch:s)
            {
                ans.push_back(ch-'0');
            }
        }
        return ans;
    }
};
