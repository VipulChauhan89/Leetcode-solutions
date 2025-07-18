class Solution {
public:
    long long minimumDifference(vector<int> &nums)
    {
        int n=nums.size()/3,len=nums.size();
        priority_queue<int> mxHp;
        priority_queue<int,vector<int>,greater<int>> mnHp;
        vector<long long> l(len),r(len+1);
        long long sum=0,ans=LLONG_MAX;
        for(int i=0;i<len;i++) 
        {
            mxHp.push(nums[i]);
            sum+=nums[i];
            if(mxHp.size()>n) 
            {
                sum-=mxHp.top();
                mxHp.pop();
            }
            if(i>=n-1) 
            {
                l[i]=sum;
            }
        }
        sum=0;
        for(int i=len-1;i>=0;i--) 
        {
            mnHp.push(nums[i]);
            sum+=nums[i];
            if(mnHp.size()>n) 
            {
                sum-=mnHp.top();
                mnHp.pop();
            }
            if(i<=len-n)
            {
                r[i]=sum;
            }
        }
        for(int i=n-1;i<2*n;i++) 
        {
            ans=min(ans,l[i]-r[i+1]);
        }
        return ans;
    }
};
