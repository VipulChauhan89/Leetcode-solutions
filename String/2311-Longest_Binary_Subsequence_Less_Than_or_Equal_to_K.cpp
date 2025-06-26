class Solution {
public:
    int longestSubsequence(string s,int k)
    {
        int n=s.size(),zero=0,one=0;
        long long value=0,pow=1;
        for(auto &i:s)
        {
            if(i=='0')
            {
                zero++;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='1')
            {
                if(value+pow>k)
                {
                    continue;
                }
                value+=pow;
                one++;
            }
            pow<<=1;
            if(pow>k)
            {
                break;
            }
        }
        return zero+one;
    }
};
