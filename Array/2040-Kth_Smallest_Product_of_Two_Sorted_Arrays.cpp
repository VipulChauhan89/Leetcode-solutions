class Solution {
public:
    long long kthSmallestProduct(vector<int> &nums1,vector<int> &nums2,long long k)
    {
        long long l=-1e10,r=1e10;
        while(l<r)
        {
            long long mid=l+(r-l)/2;
            if(countProducts(nums1,nums2,mid)<k)
            {
                l=mid+1;
            }   
            else
            {
                r=mid;
            } 
        }
        return l;
    }

    long long countProducts(vector<int> &nums1,vector<int> &nums2,long long target) 
    {
        long long count=0;
        for(auto &i:nums1)
        {
            if(num1==0)
            {
                if(target>=0)
                {
                    count+=nums2.size();
                }
                continue;
            }
            int l=0,r=nums2.size();
            while(l<r)
            {
                int mid=(l+r)/2;
                long long prod=1LL*num1*nums2[mid];
                if(prod<=target)
                {
                    if(num1>0)
                    {
                        l=mid+1;
                    } 
                    else
                    {
                        r=mid;
                    } 
                }
                else
                {
                    if(num1>0)
                    {
                        r=mid;
                    }
                    else
                    {

                    }
                    l=mid+1;
                }
            }
            count+=(num1>0)?l:(nums2.size()-l);
        }
        return count;
    }
};
