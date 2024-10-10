class Solution {
public:
    int maxWidthRamp(vector<int> &nums) 
    {
        int n=nums.size(),mx=0;
        stack<int> s;
        for(int i=0;i<n;i++) 
        {
            if(s.empty() || nums[s.top()]>nums[i]) 
            {
                s.push(i);
            }
        }
        for(int j=n-1;j>=0;j--) 
        {
            while(!s.empty() && nums[s.top()]<=nums[j]) 
            {
                mx=max(mx,j-s.top());
                s.pop();
            }
        }
        return mx;
    }
};
