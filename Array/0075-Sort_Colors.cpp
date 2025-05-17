class Solution {
public:
    void sortColors(vector<int> &nums) 
    {
        int l=0,m=0,r=nums.size()-1;
        while(m<=r)
        {
            switch(nums[m])
            {
                case 0:
                    swap(nums[l],nums[m]);
                    l++;
                    m++;
                    break;
                case 1:
                    m++;
                    break;
                case 2:
                    swap(nums[m],nums[r]);
                    r--;
            }
        }
    }
};
