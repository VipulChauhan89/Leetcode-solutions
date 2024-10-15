class Solution {
public:
    long long minimumSteps(string s) 
    {
        long long swp=0;
        int b=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='0')
            {
                swp+=(long long)b;
            }
            else
            {
                b++;
            }
        }
        return swp;
    }
};
