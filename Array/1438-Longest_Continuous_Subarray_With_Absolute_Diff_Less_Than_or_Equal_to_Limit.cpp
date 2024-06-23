class Solution {
public:
    int longestSubarray(vector<int> &nums,int limit) 
    {
        deque<int> mx,mn;
        int n=nums.size(),j=0,ans=0;
        for(int i=0;i<n;i++)
        {
            while(!mx.empty() && nums[i]>mx.back())
            {
                mx.pop_back();
            }
            mx.push_back(nums[i]);
            while(!mn.empty() && nums[i]<mn.back())
            {
                mn.pop_back();
            }
            mn.push_back(nums[i]);
            if(mx.front()-mn.front()>limit)
            {
                if(nums[j]==mx.front())
                {
                    mx.pop_front();
                }
                if(nums[j]==mn.front())
                {
                    mn.pop_front();
                }
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};
