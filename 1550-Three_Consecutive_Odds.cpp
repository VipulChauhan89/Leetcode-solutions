class Solution {
public:
    bool isOdd(int n)
    {
        return n%2;
    }
    bool threeConsecutiveOdds(vector<int> &arr) 
    {
        bool ans=false;
        for(int i=2;i<arr.size();i++)
        {
            if(isOdd(arr[i-2]) && isOdd(arr[i-1]) && isOdd(arr[i]))
            {
                ans=true;
                break;
            }
        }
        return ans;
    }
};
