class Solution {
public:
    int pivotInteger(int n) {
        int sum=n*(n+1)/2,prefixSum=0;
        for(int i=1;i<=n;i++)
        {
            if(sum-prefixSum==i)
            {
                return i;
            }
            prefixSum+=i;
            sum-=i;
        }
        return -1;
    }
};
