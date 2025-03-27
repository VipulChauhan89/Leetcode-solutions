class Solution {
public:
    int minimumIndex(vector<int> &nums) 
    {
        int n=nums.size(),count=0,xM=0;
        for(auto &i:nums) 
        {
            if(count==0) 
            {
                xM=i;
            }
            count+=(i==xM)?1:-1;
        }
        int maxF=std::count(nums.begin(),nums.end(),xM),cntxM=0;
        for(int i=0;i<n;i++) 
        {
            cntxM+=nums[i]==xM;
            if(cntxM*2>(i+1) && ((maxF-cntxM)*2>(n-i-1)))
            {
                return i;
            }
        }
        return -1;
    }
};
