class Solution {
public:
    long long countSubarrays(vector<int> &nums,int k) 
    {
        int n=nums.size(),j=0;
        long long mx=*max_element(nums.begin(),nums.end()),count=0,mxOccurance=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==mx)
            {
                mxOccurance++;
            }
            while(mxOccurance>=k)
            {
                if(nums[j]==mx)
                {
                    mxOccurance--;
                }
                j++;
            }
            count+=j;
        }
        return count;
    }
};
