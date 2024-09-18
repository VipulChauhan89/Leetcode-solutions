class Solution {
public:
    static bool comp(int a,int b) 
    {
        string sa=to_string(a),sb=to_string(b);
        return ((sa+sb)>(sb+sa));
    }
    string largestNumber(vector<int> &nums) 
    {
        sort(nums.begin(),nums.end(),comp);
        if(nums[0]==0)
        {
            return "0";
        }
        string ans="";
        for(auto i:nums)
        {
            ans+=to_string(i);
        }
        return ans;
    }
};
