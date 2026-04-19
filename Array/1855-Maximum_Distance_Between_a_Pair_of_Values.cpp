class Solution {
public:
    int maxDistance(vector<int> &nums1,vector<int> &nums2)
    {
        int n1=nums1.size(),n2=nums2.size(),i=0,j=0;
        while(i<n1 && j<n2)
        {
            if(nums1[i]>nums2[j])
            {
                i++;
            }
            j++;
        }
        return max(0,j-i-1);
    }
};
