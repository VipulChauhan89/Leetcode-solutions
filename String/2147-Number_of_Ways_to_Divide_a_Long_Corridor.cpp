class Solution {
public:
    int numberOfWays(string corridor) 
    {
        long long seat=0,ans=1,plant=0;
        for(auto i:corridor)
        {
            if(i=='S')
            {
                seat+=1;
            }
            else
            {
                if(seat==2)
                {
                    plant++;
                }
            }
            if(seat==3)
            {
                ans=(ans*(plant+1))%(1000000007);
                seat=1;
                plant=0;
            }
        }
        return (seat!=2)?0:ans;    
    }
};
