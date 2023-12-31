class Solution {
public:
    int maximumLength(string s) 
    {
        int ans=-1;
        unordered_map<string,int> m;
        for(int i=0;i<s.length();i++)
        {
            for(int j=1;j<s.length()-i+1;j++)
            {
                bool ans=true;
                string s1=s.substr(i,j);
                for(int k=0;k<s1.length();k++)
                {
                    if(s1[0]!=s1[k])
                    {
                        ans=false;
                        break;
                    }
                }
                if(ans)
                {
                    m[s1]++;
                }
            }
        }
        for(auto &i:m)
        {
            if(i.second>=3)
            {
                string s2=i.first;
                ans=max(ans,static_cast<int>(s2.length()));
            }
        }
        return ans;
    }
};
