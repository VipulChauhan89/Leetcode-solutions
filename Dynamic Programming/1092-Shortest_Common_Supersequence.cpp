class Solution {
public:
    string shortestCommonSupersequence(string str1,string str2) 
    {
        int n=str1.length(),m=str2.length();
        vector<vector<int>> lcs(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    lcs[i][j]=1+lcs[i-1][j-1];
                }
                else
                {
                    lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
                }
            }
        }
        int i=n,j=m;
        string ans="";
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                ans+=str1[i-1];
                i--;
                j--;
            }
            else if(lcs[i-1][j]>lcs[i][j-1])
            {
                ans+=str1[i-1];
                i--;
            }
            else
            {
                ans+=str2[j-1];
                j--;
            }
        }
        while(i>0)
        {
            ans+=str1[--i];
        }
        while(j>0)
        {
            ans+=str2[--j];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
