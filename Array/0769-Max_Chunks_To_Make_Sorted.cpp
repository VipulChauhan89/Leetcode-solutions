class Solution {
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int n=arr.size(),count=0,diff=0;
        for(int i=0;i<n;i++)
        {
            diff+=arr[i]-i;
            count+=(diff==0);
        }   
        return count;
    }
};
