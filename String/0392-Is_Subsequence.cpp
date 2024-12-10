class Solution {
public:
    bool isSubsequence(string s,string t) 
    {
        int i=0,j=0,ns=s.length(),nt=t.length();
        while(i<ns && j<nt)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return i==ns;
    }
};
