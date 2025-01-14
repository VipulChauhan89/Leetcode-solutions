class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int> &B) 
    {
        int n=A.size(),common=0;
        vector<int> ans,count(n,0);
        for(int i=0;i<n;i++)
        {
            count[A[i]-1]++;
            if(count[A[i]-1]==2)
            {
                common++;
            }
            count[B[i]-1]++;
            if(count[B[i]-1]==2)
            {
                common++;
            }
            ans.push_back(common);
        }
        return ans;
    }
};
