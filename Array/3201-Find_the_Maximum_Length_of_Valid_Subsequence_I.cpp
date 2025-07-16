class Solution {
public:
    int maximumLength(vector<int> &nums)
    {
        int even=0,odd=0,alteven=0,altodd=0;
        for(auto &i:nums)
        {
            if(i%2==0)
            {
                even++;
                alteven=altodd+1;
            }
            else
            {
                odd++;
                altodd=alteven+1;
            }
        }
        return max({even,odd,alteven,altodd});
    }
};
