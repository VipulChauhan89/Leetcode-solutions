class Solution {
public:
    int count(vector<int> &nums,int target) 
    {
        int ans=0;
        for(auto i:nums) 
        {
            if(i>=target)
            {
                ans++;
            } 
        }
        return ans;
    }
    int specialArray(vector<int> &nums) 
    {
        sort(nums.begin(),nums.end());
        int start=0,end=nums.size();
        while(start<=end) 
        {
            int mid=start+(end-start)/2;
            int ans=count(nums,mid);
            if(ans==mid)
            {
                return mid;
            } 
            else if(ans>mid)
            {
                start=mid+1;
            } 
            else
            {
                end=mid-1;
            } 
        }
        return -1;
    }
};
