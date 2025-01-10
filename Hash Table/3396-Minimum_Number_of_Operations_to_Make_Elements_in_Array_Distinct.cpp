class Solution {
public:
    int minimumOperations(vector<int> &nums) 
    {
        int i=nums.size()-1;
        unordered_set<int> s;
        while(i>=0)
        {
            if(s.find(nums[i])!=s.end())
            {
                break;
            }
            s.insert(nums[i]);
            i--;
        }
        i++;
        return (i%3==0?i/3:(i/3)+1);
    }
};
