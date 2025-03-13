class Solution {
public:
    bool make(vector<int> &nums,vector<vector<int>> &queries,int k)
    {
        int n=nums.size(),sum=0;
        vector<int> diff(n+1,0);
        for(int i=0;i<k;i++)
        {
            diff[queries[i][0]]-=queries[i][2];
            diff[queries[i][1]+1]+=queries[i][2];
        }
        for(int i=0;i<n;i++)
        {
            sum+=diff[i];
            if(sum+nums[i]<=0)
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int> &nums,vector<vector<int>> &queries) 
    {
        int l=0,r=queries.size(),ans=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(make(nums,queries,mid))
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
