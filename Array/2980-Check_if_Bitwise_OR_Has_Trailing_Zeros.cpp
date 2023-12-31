class Solution {
public:
    bool hasTrailingZeros(vector<int> &nums) 
    {
        int evenCount=0; 
        for(auto i:nums)
        {
            evenCount+=((i%2==0)?1:0);
        }
        return (evenCount>=2)?true:false;
    }
};
