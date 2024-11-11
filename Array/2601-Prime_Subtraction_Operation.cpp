class Solution {
public:
    int getMaxElement(vector<int> &nums) 
    {
        int mx=nums[0];
        for(int i=1;i<nums.size();i++) 
        {
            mx=max(mx,nums[i]);
        }
        return mx;
    }
    bool primeSubOperation(vector<int> &nums) 
    {
        int mxElement=getMaxElement(nums),currValue=1,k=0;
        vector<bool> sieve(mxElement+1,true);
        sieve[1]=false;
        for(int i=2;i<=sqrt(mxElement+1);i++) 
        {
            if(sieve[i]) 
            {
                for(int j=i*i;j<=mxElement;j+=i) 
                {
                    sieve[j]=false;
                }
            }
        }
        while(k<nums.size()) 
        {
            int difference=nums[k]-currValue;
            if(difference<0) 
            {
                return false;
            }
            if(sieve[difference]==true || difference==0) 
            {
                k++;
                currValue++;
            } 
            else 
            {
                currValue++;
            }
        }
        return true;
    }
};
