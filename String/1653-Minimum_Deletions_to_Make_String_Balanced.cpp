class Solution {
public:
    int minimumDeletions(string s) 
    {
        int n=s.size(),count=0,ans=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='a')
            {
                count++;
            }
            else
            {
                ans=min(ans+1,count);
            }
        }
        return ans;
    }
};
