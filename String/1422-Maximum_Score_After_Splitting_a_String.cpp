class Solution {
public:
    int maxScore(string s) 
    {
        int n=s.length(),zero=0,one=0,ans=0;
        vector<int> prefix(n),suffix(n);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                zero++;
            }
            prefix[i]=zero;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='1')
            {
                one++;
            }
            suffix[i]=one;
        }
        for(int i=0;i<n-1;i++)
        {
            ans=max(ans,suffix[i+1]+prefix[i]);
        }
        return ans;
    }
};
