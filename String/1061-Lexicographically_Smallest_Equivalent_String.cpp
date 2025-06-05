class Solution {
public:
    string smallestEquivalentString(string s1,string s2,string baseStr) 
    {
        vector<char> a(26);
        for(int i=0;i<26;i++)
        {
            a[i]='a'+i;
        }
        for(int i=0;i<s1.size();i++)
        {
            char t1=a[s1[i]-'a'],t2=a[s2[i]-'a'];
            char mn=min(t1,t2);
            for(int j=0;j<26;j++)
            {
                if(a[j]==t1 || a[j]==t2)
                {
                    a[j]=mn;
                }
            }
        }
        for(int i=0;i<baseStr.size();i++)
        {
            baseStr[i]=a[baseStr[i]-'a'];
        }
        return baseStr;
    }
};
