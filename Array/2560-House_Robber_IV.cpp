class Solution {
public:
    bool canRob(vector<int> &nums,int mid,int k) 
    {
        int c=0,n=nums.size();
        for(int i=0;i<n;i++) 
        {
            if(nums[i]<=mid)
            {
                c++;
                i++;
            }
        }
        return c>=k;
    }
    int minCapability(vector<int> &nums,int k) 
    {
        int l=1,r=*max_element(nums.begin(),nums.end()),ans=r;
        while(l<=r) 
        {
            int mid=(l+r)/2;
            if(canRob(nums,mid,k)) 
            {
                ans=mid;
                r=mid-1;
            } 
            else 
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
