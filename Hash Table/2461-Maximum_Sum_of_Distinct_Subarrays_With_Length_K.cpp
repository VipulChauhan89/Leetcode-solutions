class Solution {
public:
    long long maximumSubarraySum(vector<int> &nums,int k) 
    {
        int n=nums.size(),begin=0;
        unordered_set<int> s;
        long long current_sum=0,max_sum=0;
        for(int i=0;i<n;i++) 
        {
            if(s.find(nums[i])==s.end()) 
            {
                current_sum+=nums[i];
                s.insert(nums[i]);
                if(i-begin+1==k) 
                {
                    max_sum=max(max_sum,current_sum);
                    current_sum-=nums[begin];
                    s.erase(nums[begin]);
                    begin++;
                }
            } 
            else 
            {
                while(nums[begin]!=nums[i]) 
                {
                    current_sum-=nums[begin];
                    s.erase(nums[begin]);
                    begin++;
                }
                begin++;
            }
        }
        return max_sum;
    }
};
