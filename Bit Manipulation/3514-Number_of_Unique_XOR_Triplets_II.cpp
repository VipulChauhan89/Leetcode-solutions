class Solution {
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        int max_xor=2048,n=nums.size(),count=0;
        vector<bool> pair_xor(max_xor,false),triplet_xor(max_xor,false);
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                pair_xor[nums[i]^nums[j]]=true;
            }
        }
        for(int x=0;x<max_xor;x++)
        {
            if(!pair_xor[x])
            {
                continue;
            }
            for(int v:nums)
            {
                triplet_xor[x^v]=true;
            }
        }
        for(int i=0;i<max_xor;i++)
        {
            if(triplet_xor[i])
            {
                count++;
            }
        }
        return count;
    }
};
