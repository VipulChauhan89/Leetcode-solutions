class Solution {
public:
    int minimumOperations(vector<int> &nums) 
    {
        int count=0,temp=0;
        while(true)
        {
            unordered_map<int,int> m;
            temp=0;
            for(auto &i:nums)
            {
                if(++m[i]==2)
                {
                    temp++;
                }
            }
            if(temp==0)
            {
                break;
            }
            nums.erase(nums.begin(),nums.begin()+min(3,(int)nums.size()));
            count++;
        }    
        return count;
    }
};
