class Solution {
public:
    int majorityElement(vector<int> &nums) 
    {
        unordered_map<int,int> m;
        int n=nums.size(),ans=nums[0];
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
            if(m[nums[i]]>n/2)
            {
                ans=nums[i];
                break;
            }
        }    
        return ans;
    }
};
