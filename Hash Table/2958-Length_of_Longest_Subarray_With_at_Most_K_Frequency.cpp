class Solution {
public:
    int maxSubarrayLength(vector<int> &nums,int k) 
    {
        unordered_map<int,int> m;
        int n=nums.size(),l=0,r=0,count{};
        while(r<n)
        {
            int cur=nums[r++];
            m[cur]++;
            while(l<r && m[cur]>k)
            {
                m[nums[l++]]--;
            }
            count=max(count,r-l);
        }    
        return count;
    }
};
