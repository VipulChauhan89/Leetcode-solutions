class Solution {
public:
    vector<int> sumZero(int n)
    {
        vector<int> ans(n);
        ans[0]=n*(1-n)/2;
        for(int i=1;i<n;i++)
        {
            ans[i]=i;
        }
        return ans;
    }
};
