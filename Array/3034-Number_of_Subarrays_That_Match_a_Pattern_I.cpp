class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n=nums.size(),m=pattern.size(),count=0;
        for(int i=0;i<n-m;i++) 
        {
            bool valid=true;
            for(int j=0;j<m;j++) 
            {
                if(pattern[j]==1 && nums[i+j+1]<=nums[i+j]) 
                {
                    valid=false;
                    break;
                }
                else if(pattern[j]==0 && nums[i+j+1]!=nums[i+j]) 
                {
                    valid=false;
                    break;
                }
                else if(pattern[j]==-1 && nums[i+j+1]>=nums[i+j]) 
                {
                    valid=false;
                    break;
                }
            }
            if(valid) 
            {
                count++;
            }
        }
        return count;
    }
};
