class Solution {
public:
    int minSteps(int n) 
    {
        if(n==1)
        {
            return 0;
        }
        int step=0,f=2;
        while(n>1)
        {
            while(n%f==0)
            {
                step+=f;
                n/=f;
            }
            f++;
        }
        return step;
    }
};
