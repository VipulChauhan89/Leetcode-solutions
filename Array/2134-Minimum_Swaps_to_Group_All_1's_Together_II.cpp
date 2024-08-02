class Solution {
public:
    int minSwaps(vector<int> &nums) 
    {
        int n=nums.size(),total=accumulate(nums.begin(),nums.end(),0);
        if(total==0 || total==n)
        {
            return 0;
        }
        int current=accumulate(nums.begin(),nums.begin()+total,0);
        int mx=current;
        for(int i=0;i<n;i++)
        {
            current-=nums[i];
            current+=nums[(i+total)%n];
            mx=max(mx,current);
        }
        return total-mx;
    }
};
