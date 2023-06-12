class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {    
        int size=nums.size(),i=0;
        vector<string> ans;
        if(size==0)
        {
            return ans;
        }
        while(i<size)
        {
            int l=i,h=i;
            while(h+1<size && nums[h+1]==nums[h]+1)
            {
                h++;
            }
            if(h>l)
            {
                ans.push_back(to_string(nums[l])+"->"+to_string(nums[h]));
            }
            else
            {
                ans.push_back(to_string(nums[h]));
            }
            i=h+1;
        }
        return ans;
    }
};
