class Solution {
public:
    int getMinDistance(vector<int> &nums,int target,int start)
    {
        int mn=INT_MAX,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target)
            {
                mn=min(mn,abs(start-i));
            }
        }
        return mn;
    }
};
