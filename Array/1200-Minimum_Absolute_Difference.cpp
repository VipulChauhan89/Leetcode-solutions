class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        sort(arr.begin(),arr.end());
        int minDiff=INT_MAX,n=arr.size();
        vector<vector<int>> ans;
        for(int i=1;i<arr.size();i++)
        {
            int diff=arr[i]-arr[i-1];
            if(diff<minDiff)
            {
                minDiff=diff;
                ans={};
                ans.push_back({arr[i-1],arr[i]});
            }
            else if(diff==minDiff)
            {
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};
