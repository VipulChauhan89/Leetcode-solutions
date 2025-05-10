class Solution {
public:
    long long minSum(vector<int> &nums1,vector<int> &nums2) 
    {
        long long s1=0,s2=0;
        int z1=0,z2=0;
        for(auto &i:nums1)
        {
            if(i!=0)
            {
                s1+=i;
            }
            else
            {
                z1++;
            }
        }
        for(auto &i:nums2)
        {
            if(i!=0)
            {
                s2+=i;
            }
            else
            {
                z2++;
            }
        }
        if(z1==0 && z2==0)
        {
            return ((s1==s2)?s1:-1);
        }
        else if(z1==0)
        {
            return ((s2+z2<=s1)?s1:-1);
        }
        else if(z2==0)
        {
            return ((s1+z1<=s2)?s2:-1);
        }
        return max(s1+z1,s2+z2);
    }
};
