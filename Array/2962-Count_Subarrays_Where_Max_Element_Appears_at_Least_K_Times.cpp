class Solution {
public:
    long long countSubarrays(vector<int> &nums,int k) 
    {
        long long mx=*max_element(nums.begin(),nums.end()),c=0,l=0,r=0,ans=0;
        while(r<nums.size())
        {
            if(nums[r]==mx)
            {
                c++;
            }
            while(c>=k)
            {
                if(nums[l]==mx)
                {
                    c--;
                }
                l++;
                ans+=nums.size()-r;
            }
            r++;
        }    
        return ans;
    }
};
