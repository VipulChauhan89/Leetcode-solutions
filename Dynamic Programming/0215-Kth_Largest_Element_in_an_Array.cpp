class Solution {
public:
    int findKthLargest(vector<int> &nums,int k) 
    {
        int ans=0;
        map<int,int,greater<int>> m;
        for(auto i:nums)
        {
            m[i]++;
        }
        for(auto i:m)
        {
            if(k<=i.second)
            {
                ans=i.first;
                break;
            }
            else
            {
                k-=i.second;
            }
        }
        return ans;
    }
};
