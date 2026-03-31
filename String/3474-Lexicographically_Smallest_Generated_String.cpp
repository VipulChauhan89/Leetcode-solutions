class Solution {
public:
    string generateString(string str1,string str2)
    {
        int n=str1.size(),m=str2.size();
        string ans(n+m-1,'?');
        for(int i=0;i<n;i++)
        {
            if(str1[i]!='T')
            {
                continue;
            }
            for(int j=0;j<m;j++)
            {
                char v=ans[i+j];
                if(v!='?' && v!=str2[j])
                {
                    return "";
                }
                ans[i+j]=str2[j];
            }
        }
        string old_ans=ans;
        for(char&c:ans)
        {
            if(c=='?')
            {
                c='a';
            }
        }
        for(int i=0;i<n;i++)
        {
            if(str1[i]!='F')
            {
                continue;
            }
            if(string(ans.begin()+i,ans.begin()+i+m)!=str2)
            {
                continue;
            }
            bool ok=false;
            for(int j=i+m-1;j>=i;j--)
            {
                if(old_ans[j]=='?')
                {
                    ans[j]='b';
                    ok=true;
                    break;
                }
            }
            if(!ok)
            {
                return "";
            }
        }
        return ans;
    }
};
