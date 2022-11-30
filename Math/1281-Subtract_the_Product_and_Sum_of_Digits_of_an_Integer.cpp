class Solution {
public:
    int subtractProductAndSum(int n) 
    {
        int sum=0,product=1;
        while(n!=0)
        {
            int num=n%10;
            product*=num;
            sum+=num;
            n/=10;
        }
        return product-sum;
    }
};
