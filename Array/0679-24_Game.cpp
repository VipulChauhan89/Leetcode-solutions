class Solution {
public:
    vector<double> compute(double a,double b)
    {
        vector<double> ans={a+b,a-b,b-a,a*b};
        if(fabs(b)>1e-6)
        {
            ans.push_back(a/b);
        }
        if(fabs(a)>1e-6)
        {
            ans.push_back(b/a);
        }
        return ans;
    }
    bool dfs(vector<double> nums)
    {
        if(nums.size()==1)
        {
            return fabs(nums[0]-24)<1e-6;
        }
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                vector<double> next;
                for(int k=0;k<nums.size();k++)
                {
                    if(k!=i && k!=j)
                    {
                        next.push_back(nums[k]);
                    }
                }
                for(double x:compute(nums[i],nums[j]))
                {
                    next.push_back(x);
                    if(dfs(next))
                    {
                        return true;
                    }
                    next.pop_back();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int> &cards)
    {
        vector<double> nums(cards.begin(),cards.end());
        return dfs(nums);   
    }
};
