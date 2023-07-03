class Solution {
public:
    bool buddyStrings(string s,string goal) 
    {
        int n=s.size(),m=goal.size();
        if(n!=m)
        {
            return false;
        }
        if(s==goal)
        {
            vector<int> arr(26,0);
            for(auto i:s)
            {
                arr[i-'a']++;
                if(arr[i-'a']==2)
                {
                    return true;
                }
            }
            return false;
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=goal[i])
            {
                ans.push_back(i);
            }
            if(ans.size()>2)
            {
                return false;
            }
        }
        return (ans.size()==2 && s[ans[0]]==goal[ans[1]] && s[ans[1]]==goal[ans[0]]);
    }
};
