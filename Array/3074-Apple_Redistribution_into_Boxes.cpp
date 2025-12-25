class Solution {
public:
    int minimumBoxes(vector<int> &apple,vector<int> &capacity)
    {
        int sum=accumulate(apple.begin(),apple.end(),0),ans=0;
        sort(capacity.begin(),capacity.end(),greater<int>());
        while(sum>0)
        {
            sum-=capacity[ans++];
        }
        return ans;
    }
};
