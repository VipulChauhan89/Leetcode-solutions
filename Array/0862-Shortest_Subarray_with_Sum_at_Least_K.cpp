class Solution {
public:
    int shortestSubarray(vector<int> &nums,int k) 
    {
        int ans=INT_MAX;
        long long sum=0;
        deque<pair<long long,int>> q;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>=k)
            {
                ans=min(ans,i+1);
            }
            while(!q.empty() && sum-q.front().first>=k)
            {
                auto [prefix,end]=q.front();
                q.pop_front();
                ans=min(ans,i-end);
            }
            while(!q.empty() && q.back().first>sum)
            {
                q.pop_back();
            }
            q.push_back({sum,i});
        }
        return ans==INT_MAX?-1:ans;
    }
};
