class Solution {
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        sort(folder.begin(),folder.end());
        vector<string> ans;
        for(auto &i:folder)
        {
            if(ans.empty())
            {
                ans.push_back(i);
            }
            else
            {
                string prev=ans.back();
                if(i.find(prev)==0 && i.size()>prev.size() && i[prev.size()]=='/')
                {
                    continue;
                }
                else
                {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};
