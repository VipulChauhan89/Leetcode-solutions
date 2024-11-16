class Solution {
public:
    vector<int> resultsArray(vector<int> &nums,int k) 
    {
        vector<int> ans;
        int count=1,j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i-1]+1==nums[i])
            {
                count++;
            }
            if(i-j+1>k)
            {
                if(nums[j]+1==nums[j+1])
                {
                    count--;
                }
                j++;
            }
            if(i-j+1==k)
            {
                ans.push_back(count==k?nums[i]:-1);
            }
        }
        return ans;
    }
};
