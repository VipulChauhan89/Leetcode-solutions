class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n=nums.size();
        vector<int> sum(n,0);
        vector<bool> ans;
        for(int i=1;i<n;i++)
        {
            sum[i]=sum[i-1];
            if(nums[i]%2==nums[i-1]%2)
            {
                sum[i]++;
            }
        }
        for(auto &i:queries)
        {
            int x=i[0],y=i[1],fl=sum[y]-(x>0?sum[x]:0);
            if(fl && x!=y)
            {
                ans.push_back(false);
            }
            else
            {
                ans.push_back(true);
            }
        }
        return ans;
    }
};
