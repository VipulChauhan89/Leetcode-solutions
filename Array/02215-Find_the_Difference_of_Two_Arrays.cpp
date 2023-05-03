class Solution {
public:
    vector<vector<int>> findDifference(vector<int> &nums1,vector<int> &nums2) 
    {
        unordered_set<int> m1(nums1.begin(), nums1.end()),m2(nums2.begin(), nums2.end());
        vector<int> ans1,ans2;
        for(int num:m1) 
        {
            if(m2.count(num)==0) 
            {
                ans1.push_back(num);
            }
        }
        for(int num:m2) 
        {
            if(m1.count(num)==0) 
            {
                ans2.push_back(num);
            }
        }
        return {ans1,ans2};
    }
};
