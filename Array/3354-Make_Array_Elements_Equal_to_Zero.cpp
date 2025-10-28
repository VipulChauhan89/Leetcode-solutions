class Solution {
public:
    int countValidSelections(vector<int> &nums)
    {
        int total=accumulate(nums.begin(),nums.end(),0LL),ls=0,cases=0;
        for(auto &i:nums)
        {
            int rs=total-ls-i;
            if(i==0)
            {
                if(ls==rs)
                {
                    cases+=2;
                }
                else if(ls==rs-1 || ls-1==rs)
                {
                    cases++;
                }
            }
            ls+=i;
        }
        return cases;
    }
};
