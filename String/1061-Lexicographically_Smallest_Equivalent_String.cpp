class Solution {
public:
    string smallestEquivalentString(string s1,string s2,string baseStr) 
    {
        int mx,mn;
        vector<int> m(26);
        for(int i=0;i<26;i++)
        {
          m[i]='a'+i;
        }
        for(int i=0;i<s1.size();i++)
        {
            mx=max(m[s1[i]-'a'],m[s2[i]-'a']);
            mn=min(m[s1[i]-'a'],m[s2[i]-'a']);
            for(int i=0;i<26;i++)
            {
                if(m[i]==mx)
                {
                    m[i]=mn;
                }
            }
        }
        for(int i=0;i<baseStr.size();i++)
        {
            baseStr[i]=m[baseStr[i]-'a'];
        }
        return baseStr;
    }
};
