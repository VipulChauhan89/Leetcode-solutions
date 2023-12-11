class Solution {
public:
    int findSpecialInteger(vector<int> &arr) 
    {
        unordered_map<int,int> m;
        int ans=-1;
        float n=arr.size()*0.25;
        for(auto i:arr)
        {
            m[i]++;
            if(m[i]>n)
            {
                ans=i;
            }
        }
        return ans;
    }
};
