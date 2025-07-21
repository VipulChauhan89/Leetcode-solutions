class Solution {
public:
    string makeFancyString(string s)
    {
        string ans="";
        for(auto &i:s)
        {
            if(ans.size()>=2 && ans.back()==i && ans[ans.size()-2]==i)
            {
                continue;
            }
            ans.push_back(i);
        }
        return ans;
    }
};
