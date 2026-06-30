class Solution {
public:
    int numberOfSubstrings(string s)
    {
        int ans=0;
        vector<int> p={-1,-1,-1};
        for(int i=0;i<s.length();i++)
        {
            p[(s[i]&31)-1]=i;
            ans+=min({p[0],p[1],p[2]})+1;
        }
        return ans;
    }
};
