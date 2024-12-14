class Solution {
public:
    long long continuousSubarrays(vector<int> &nums) 
    {
        int l=0;
        long long ans=0;
        deque<int> mn,mx;
        for(int i=0;i<nums.size();i++)
        {
            while(!mn.empty() && nums[mn.back()]>=nums[i])
            {
                mn.pop_back();
            }
            while(!mx.empty() && nums[mx.back()]<=nums[i])
            {
                mx.pop_back();
            }
            mn.push_back(i);
            mx.push_back(i);
            while(nums[mx.front()]-nums[mn.front()]>2)
            {
                l++;
                if(mn.front()<l)
                {
                    mn.pop_front();
                }
                if(mx.front()<l)
                {
                    mx.pop_front();
                }
            }
            ans+=i-l+1;
        }
        return ans;
    }
};
