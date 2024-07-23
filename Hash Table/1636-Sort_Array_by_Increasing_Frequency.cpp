class Solution {
public:
    
    
    vector<int> frequencySort(vector<int> &nums) 
    {
        unordered_map<int,int> m;
        for(auto i:nums)
        {
            m[i]++;
        }
        sort(nums.begin(),nums.end(),[&](int a,int b){
            if(m[a]!=m[b])
            {
                return m[a]<m[b];
            }
            else
            {
                return a>b;
            }
        });
        return nums;
    }
};
