class Solution {
public:
    bool isPalindrome(string s,int l,int r)
    {
        while(l<r)
        {
            if(s[l++]!=s[r--])
            {
                return false;
            }
        }
        return true;
    }
    int countSubstrings(string s) 
    {
        int ans=0,n=s.length();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(isPalindrome(s,i,j))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
