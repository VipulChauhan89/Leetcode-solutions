class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int ans=0;
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
            if(m[nums[i]]>=nums.size()*0.5)
            {
                ans=nums[i];
            }
        }
        return ans;
    }
};
