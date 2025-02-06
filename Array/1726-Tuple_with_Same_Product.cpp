class Solution {
public:
    int tupleSameProduct(vector<int> &nums) 
    {
        int n=nums.size(),nn=n*(n-1)/2,ans=0;
        vector<int> product;
        product.reserve(nn);
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                product.push_back(nums[i]*nums[j]);
            }
        }
        sort(product.begin(),product.end());
        int j=1,f=1;
        for(int i=2;i<nn;i++)
        {
            if(product[j]==product[i])
            {
                f++;
            }
            else
            {
                if(f>1)
                {
                    ans+=f*(f-1)*4;
                }
                f=1;
                j=i;
            }
        }
        return ans;
    }
};
