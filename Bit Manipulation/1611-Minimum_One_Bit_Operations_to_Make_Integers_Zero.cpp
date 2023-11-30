class Solution {
public:
    int minimumOneBitOperations(int n) 
    {
        int ans=0;
        while(n>0)
        {
            ans=-(ans+(n^(n-1)));
            n&=n-1;
        }    
        return abs(ans);
    }
};
