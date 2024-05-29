class Solution {
public:
    int numSteps(string s) 
    {
        int c=0,st=0;
        for(int i=s.length()-1;i>0;i--)
        {
            if(s[i]-'0'+c==1)
            {
                st+=2;
                c=1;
            }
            else
            {
                st++;
            }
        }
        return st+c;
    }
};
