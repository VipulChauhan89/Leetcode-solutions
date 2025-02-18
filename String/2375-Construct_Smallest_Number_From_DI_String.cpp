class Solution {
public:
    string smallestNumber(string pattern) 
    {
        int n=pattern.length(),index=0;
        string ans="";
        vector<int> v(n+1);
        for(int i=0;i<=n;i++)
        {
            v[index++]=i+1;
            if(i==n || pattern[i]=='I')
            {
                while(index>0)
                {
                    ans+=to_string(v[--index]);
                }
            }
        }
        return ans;
    }
};
