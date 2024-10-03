class Solution {
public:
    int minSubarray(vector<int> &nums,int p) 
    {
        long total=accumulate(nums.begin(),nums.end(),0L);
        int rem=total%p;
        if(rem==0)
        {
            return 0;
        }
        unordered_map<int,int> m;
        m[0]=-1;
        long sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int current=sum%p;
            int target=(current-rem+p)%p;
            if(m.find(target)!=m.end())
            {
                n=min(n,i-m[target]);
            }
            m[current]=i;
        }
        return (n==nums.size()?-1:n);
    }
};
