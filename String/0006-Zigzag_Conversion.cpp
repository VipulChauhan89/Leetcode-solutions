class Solution {
public:
    string convert(string s, int numRows) 
    {
        if(numRows==1)
        {
            return s;
        }
        string ans="";
        for(int i=0;i<numRows;i++)
        {
            int nextindex=(numRows-1)*2;
            for(int j=i;j<s.size();j+=nextindex)
            {
                ans+=s[j];
                int temp=j+nextindex-2*i;
                if( i!=0 && i!=numRows-1 && temp<s.size())
                {
                    ans+=s[temp]; 
                }
            }
        }
        return ans;
    }
};
