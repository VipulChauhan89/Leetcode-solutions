class Solution {
public:
    int countHomogenous(string s) 
    {
        const int mod=1e9+7;
        int n=s.length(),ans=0,j=0;
        for(int i=0;i<n;i++)
        {
            while(s[i]!=s[j])
            {
                j++;
            }
            if(s[i]==s[j])
            {
                ans=(ans+(i-j+1))%mod;
            }
        }
        return ans;
    }
};
