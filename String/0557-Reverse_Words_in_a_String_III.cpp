class Solution {
public:
    string reverseWords(string s) 
    {
        int i=0,j=0;
        for(int k=0;k<s.size();k++)
        {            
            if(s[k]==' ' || k==s.size()-1)
            {
                if(k==s.size()-1)
                {
                    j=s.size();
                }
                reverse(s.begin()+i,s.begin()+j);i=j+1;
            }
            j++;
        }
        return s;
    }
};
