class Solution {
public:
    int minOperations(vector<int> &nums,int k) 
    {
        int xo=0,count=0;
        for(int i=0;i<nums.size();i++)
        {
            xo^=nums[i];
        }
        while(xo || k)
        {
            if((k%2)!=(xo%2))
            {
                count++;
            }
            xo/=2;
            k/=2;
        }
        return count;
    }
};
