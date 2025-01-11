class Solution {
public:
    int maxDistinctElements(vector<int> &nums,int k) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans={nums[0]-k};
        for(int i=1;i<n;i++)
        {
            int start=nums[i]-k,end=nums[i]+k,x=max(ans.back()+1,start);
            if(x>end)
            {
                continue;
            }
            ans.push_back(x);
        }
        return ans.size();
    }
};
