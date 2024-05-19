class Solution {
public:
    long long calculateMax(vector<int> &nums,int n,int k,int curInd,int isEven,vector<vector<long long>> &temp) 
    {
        if(curInd==n) 
        { 
            return isEven==1?0:LLONG_MIN;
        }
        if(temp[curInd][isEven]!=-1) 
        { 
            return temp[curInd][isEven];
        }
        long long noXor=nums[curInd]+calculateMax(nums,n,k,curInd+1,isEven,temp);
        long long withXor=(nums[curInd]^k)+calculateMax(nums,n,k,curInd+1,!isEven,temp);
        long long mxPossible=max(noXor,withXor);
        temp[curInd][isEven]=mxPossible;
        return mxPossible;
    }
    long long maximumValueSum(vector<int> &nums,int k,vector<vector<int>> &edges) 
    {
        int n=nums.size();
        vector<vector<long long>> temp(n,vector<long long>(2,-1));
        return calculateMax(nums,n,k,0,1,temp);
    }
};
