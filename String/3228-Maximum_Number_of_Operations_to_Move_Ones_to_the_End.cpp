class Solution {
public:
    int maxOperations(string s)
    {
        int n=s.size(),ans=0,count=0;
        bool flag=true;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0' && flag)
            {
                ans+=count;
                flag=false;
            }
            else if(s[i]=='1')
            {
                count++;
                flag=true;
            }
        }
        return ans;
    }
};
