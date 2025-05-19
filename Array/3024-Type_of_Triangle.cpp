class Solution {
public:
    string triangleType(vector<int> &nums) 
    {
        int a=nums[0],b=nums[1],c=nums[2];
        if((a+b<=c) || (a+c<=b) || (b+c<=a))
        {
            return "none";
        }
        unordered_set<int> s;
        for(auto &i:nums)
        {
            s.insert(i);
        }
        return (s.size()==1?"equilateral":(s.size()==2?"isosceles":"scalene"));
    }
};
