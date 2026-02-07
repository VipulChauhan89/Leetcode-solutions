class Solution {
public:
    int minimumDeletions(string s)
    {
        int n=s.size(),ans=n,a=0,b=0;
        for(auto &i:s)
        {
            a+=i&1;
        }
        for(auto &i:s)
        {
            a-=i&1;
            ans=min(ans,a+b);
            b+=~i&1;
        }
        return ans;
    }
};
