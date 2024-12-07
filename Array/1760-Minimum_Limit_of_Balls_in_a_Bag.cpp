class Solution {
public:
    int minimumSize(vector<int> &nums, int maxOperations) {
        int l=1,h=*max_element(nums.begin(),nums.end());
        while(l<h) 
        {
            int mid=l+(h-l)/2,op=0;
            for(auto i:nums) 
            {
                op+=(i-1)/mid;
                if(op>maxOperations)
                {
                    break;
                } 
            }
            if(op<=maxOperations) 
            {
                h=mid;
            } 
            else 
            {
                l=mid+1;
            }
        }
        return h;
    }
};
