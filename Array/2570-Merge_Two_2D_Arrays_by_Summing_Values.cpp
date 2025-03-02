class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>> &nums2) 
    {
        int i=0,j=0,n1=nums1.size(),n2=nums2.size();
        vector<vector<int>> ans;
        while(i<n1 && j<n2) 
        {
            int id1=nums1[i][0],val1=nums1[i][1],id2=nums2[j][0],val2=nums2[j][1];
            if(id1<id2) 
            {
                ans.push_back({id1,val1});
                i++;
            } 
            else if(id2<id1) 
            {
                ans.push_back({id2,val2});
                j++;
            } 
            else 
            {
                ans.push_back({id1,val1+val2});
                i++;
                j++;
            }
        }
        while(i<n1) 
        {
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<n2) 
        {
            ans.push_back(nums2[j]);
            j++;
        }
        return ans;
    }
};
