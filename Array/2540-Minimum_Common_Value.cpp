class Solution {
public:
    int getCommon(vector<int> &nums1,vector<int> &nums2) 
    {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0,n1=nums1.size(),n2=nums2.size();
        int ans=-1;
        while(i<n1 && j<n2)
        {
            if(nums1[i]==nums2[j])
            {
                ans=nums1[i];
                break;
            }
            else if(nums1[i]<nums2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return ans;
    }
};
