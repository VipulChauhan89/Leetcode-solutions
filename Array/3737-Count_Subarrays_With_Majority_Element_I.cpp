class Solution {
public:
    int countMajoritySubarrays(vector<int> &nums,int target)
    {
        int n=nums.size(),ans=0;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=i;j<n;j++)
            {
                count+=(nums[j]==target?1:-1);
                if(count>0)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
