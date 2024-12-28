class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums,int k) 
    {
        int n=nums.size(),windowSum=0,leftMaxIndex=0,rightMaxIndex=n-k,maxSum=0;
        vector<int> sums(n-k+1,0),left(n-k+1,0),right(n-k+1,0),ans(3);
        for(int i=0;i<n;i++) 
        {
            windowSum+=nums[i];
            if(i>=k-1) 
            {
                sums[i-k+1]=windowSum;
                windowSum-=nums[i-k+1];
            }
        }
        for(int i=0;i<n-k+1;i++) 
        {
            if(sums[i]>sums[leftMaxIndex]) 
            {
                leftMaxIndex=i;
            }
            left[i]=leftMaxIndex;
        }
        for(int i=n-k;i>=0;i--) 
        {
            if(sums[i]>=sums[rightMaxIndex]) 
            {
                rightMaxIndex=i;
            }
            right[i]=rightMaxIndex;
        }
        for(int i=k;i<n-k+1-k;i++) 
        {
            int l=left[i-k],r=right[i+k],totalSum=sums[l]+sums[i]+sums[r];
            if(totalSum>maxSum) 
            {
                maxSum=totalSum;
                ans={l,i,r};
            }
        }
        return ans;
    }
};
