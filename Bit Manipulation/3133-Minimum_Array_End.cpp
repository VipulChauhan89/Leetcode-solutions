class Solution {
public:
    long long minEnd(int n,int x) 
    {
        long long ans=x,rem=n-1,pos=1;
        while(rem)
        {
            if(!(x&pos))
            {
                ans|=(rem&1)*pos;
                rem>>=1;
            }
            pos<<=1;
        }
        return ans;
    }
};
