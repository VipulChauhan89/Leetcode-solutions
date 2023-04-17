class Solution {
public:
    vector<bool> kidsWithCandies(vector<int> &candies,int extraCandies) 
    {
        vector<bool> ans;
        int mx=*max_element(candies.begin(),candies.end());
        for(auto i:candies)
        {
            if(i+extraCandies>=mx)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        return ans;
    }
};
