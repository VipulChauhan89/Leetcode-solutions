class Solution {
public:
    int process(string &s)
    {
        int i=0;
        for(auto c:s)
        {
            if(c!='#')
            {
                s[i++]=c;
            }
            else if(i>0)
            {
                i--;
            }
        }
        return i;
    }
    bool backspaceCompare(string s,string t) 
    {
        int k=process(s);
        if(k!=process(t))
        {
            return false;
        }
        for(int i=0;i<k;i++)
        {
            if(s[i]!=t[i])
            {
                return false;
            }
        }
        return true;
    }
};
