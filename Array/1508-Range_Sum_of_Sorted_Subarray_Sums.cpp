class Solution {
public:
    int rangeSum(vector<int> &nums,int n,int left,int right) 
    {
        int ans=0,mod=1e9+7;
        vector<int> arr(n*(n+1)/2);
        for(int i=0,k=0;i<n;i++) 
        {
            int s=0;
            for(int j=i;j<n;j++) 
            {
                s+=nums[j];
                arr[k++]=s;
            }
        }
        sort(arr.begin(),arr.end());
        for(int i=left-1;i<right;i++) 
        {
            ans=(ans+arr[i])%mod;
        }
        return ans;
    }
};
