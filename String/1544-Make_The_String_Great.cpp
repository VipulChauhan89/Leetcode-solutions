class Solution {
public:
    string makeGood(string s) 
    {
        string ans;
        for(auto i:s)
        {
            if(!ans.empty() && abs(ans.back()-i)==32)
            {
                ans.pop_back();
            }
            else
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
