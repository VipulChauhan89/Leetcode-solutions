class Solution {
public:
    vector<int> getFinalState(vector<int> &nums,int k,int multiplier) 
    {
        int n=nums.size();
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++)
        {
            a[i]={nums[i],i};
        }
        make_heap(a.begin(),a.end(),greater<>{});
        for(int i=0;i<k;i++)
        {
            pop_heap(a.begin(),a.end(),greater<>{});
            a.back().first*=multiplier;
            push_heap(a.begin(),a.end(),greater<>{});
        }
        for(auto &i:a)
        {
            nums[i.second]=i.first;
        }
        return nums;
    }
};
