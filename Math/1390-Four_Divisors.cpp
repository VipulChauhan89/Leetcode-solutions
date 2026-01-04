class Solution {
public:
    int factor(int n)
    {
        int sum=0,c=0;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                int j=n/i;
                if(j==i || c>0)
                {
                    return 0;
                }
                sum+=i+j;
                c++;
            }
        }
        if(c==0)
        {
            return 0;
        }
        return 1+sum+n;
    }
    int sumFourDivisors(vector<int> &nums)
    {
        int sum=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=factor(nums[i]);
        }
        return sum;
    }
};
