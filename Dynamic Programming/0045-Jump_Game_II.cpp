class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int max_distance=0,jump=0,distance=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            max_distance=max(max_distance,i+nums[i]);
            if(distance==i)
            {
                distance=max_distance;
                jump++;
            }
        }
        return jump;
    }
};
