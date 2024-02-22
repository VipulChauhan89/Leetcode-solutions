class Solution {
public:
    int findJudge(int n,vector<vector<int>> &trust) 
    {
        vector<int> f(n+1),s(n+1);
        for(auto i:trust)
        {
            s[i[0]]++;
            f[i[1]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(f[i]==n-1 && s[i]==0)
            {
                return i;
            }
        }
        return -1;
    }
};
