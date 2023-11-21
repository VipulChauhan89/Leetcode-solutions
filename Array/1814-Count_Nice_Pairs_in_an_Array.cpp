class Solution {
public:
    int reverse(int num)
    {
        int rev=0;
        while(num>0)
        {
            rev=rev*10+num%10;
            num/=10;
        }
        return rev;
    }
    int countNicePairs(vector<int> &nums) 
    {
        const int mod=1000000007;
        int len=nums.size();
        for(int i=0;i<len;i++)
        {
            nums[i]-=reverse(nums[i]);
        }  
        sort(nums.begin(),nums.end());
        long ans=0;
        for(int i=0;i<len-1;i++)
        {
            long count=1;
            while(i<len-1 && nums[i]==nums[i+1])
            {
                count++;
                i++;
            }
            ans=(ans%mod+(count*(count-1))/2)%mod;
        }  
        return static_cast<int>(ans%mod);
    }
};
