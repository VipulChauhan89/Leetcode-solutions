class Solution {
public:
    vector<int> pivotArray(vector<int> &nums,int pivot)
    {
        int n=nums.size();
        if(n==1)
        {
            return nums;
        }
        vector<int> R;
        int l=0,m=0,sz=n;
        for(int x: nums)
        {
            if(x<pivot)
            {
                nums[l++]=x;
            }
            else if(x>pivot)
            {
                R.push_back(x);
                sz--;
            }
            else
            {
                m++;
            }
        }
        auto it_m=nums.begin()+l;
        fill(it_m,it_m+m,pivot);
        copy(R.begin(),R.end(),it_m+m);
        return nums;
    }
};
