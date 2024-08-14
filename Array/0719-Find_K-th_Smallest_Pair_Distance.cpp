class Solution {
public:
    int countPairs(vector<int> &nums,int distance)
    {
        int count=0,j=0;
        for(int i=1;i<nums.size();i++)
        {
            while(nums[i]-nums[j]>distance)
            {
                j++;
            }
            count+=i-j;
        }
        return count;
    }
    int smallestDistancePair(vector<int> &nums,int k) 
    {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.back()-nums.front();
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(countPairs(nums,mid)<k)
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        return l;
    }
};
