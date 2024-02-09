class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size(),mx=0;
        vector<int> gS(n,1),pE(n,-1),ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && gS[i]<gS[j]+1)
                {
                    gS[i]=gS[j]+1;
                    pE[i]=j;
                }
            }
            if(gS[i]>gS[mx])
            {
                mx=i;
            }
        }
        for(int i=mx;i!=-1;i=pE[i])
        {
            ans.insert(ans.begin(),nums[i]);
        }
        return ans;
    }
};
