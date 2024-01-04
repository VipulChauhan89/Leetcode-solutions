class Solution {
public:
    int minOperations(vector<int> &nums) 
    {
        int ans=0;
        unordered_map<int,int> m;
        for(auto i:nums)
        {
            m[i]++;
        }
        for(auto &i:m)
        {
            if(i.second<2)
            {
                ans=-1;
                break;
            }
            else
            {
                while(i.second>3)
                {
                    ans++;
                    i.second-=3;
                }
                if(i.second!=0)
                {
                    ans++;
                }
            }
            
        }
        return ans;
    }
};
