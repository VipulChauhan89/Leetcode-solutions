class Solution {
public:
    int minDeletions(string s) 
    {
        map<char,int> m;
        vector<int> ans;
        for(auto i:s)
        {
            m[i]++;
        }
        for(auto i:m)
        {
            ans.push_back(i.second);
        }
        sort(ans.begin(),ans.end(),greater<int>());
        int count=0;
        for(int i=1;i<ans.size();i++)
        {
            while(ans[i]>=ans[i-1] && ans[i]>0)
            {
                ans[i]--;
                count++;
            }
        }
        return count;
    }
};
