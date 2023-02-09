class Solution {
public:
    long long distinctNames(vector<string>& ideas) 
    {
        unordered_map<int,unordered_map<string,int>>m;
        long long ans=0;
        for(auto s:ideas)
        {
            m[s[0]-'a'][(s.substr(1))]++;
        }
        for(int i=0;i<25;i++)
        {
            for(int j=i+1;j<26;j++)
            {
                long long c1=0,c2=0;
                for(auto x:m[i])
                {
                    c1+=(!m[j].count(x.first));
                }
                for(auto x:m[j])
                {
                    c2+=(!m[i].count(x.first));
                }
                ans+=(c1*c2*2);
            }
        }
        return ans;
    }
};
