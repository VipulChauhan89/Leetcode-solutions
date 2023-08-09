class Solution {
public:
    int minimizeMax(vector<int> &nums,int p) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size(),l=0,h=nums.back()-nums.front();
        while(l<h)
        {
            int count=0,mid=l+(h-l)/2;
            for(int i=1;i<n;i++)
            {
                if(nums[i]-nums[i-1]<=mid)
                {
                    count++;
                    i++;
                }
            }
            if(count<p)
            {
                l=mid+1;
            }
            else
            {
                h=mid;
            }
        }
        return l;
    }
};
