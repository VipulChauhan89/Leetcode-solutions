class Solution {
public:
    int numSub(string s)
    {
        int count=0,total=0,mod=1e9+7;
        for(char a:s)
        {
            if(a=='1')
            {
                count++;
            }
            else
            {
                count=0;
            }
            total=(total+count)%mod;
        }
        return total;
    }
};
