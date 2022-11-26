class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        stack<int> st;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]!=0)
            {
                st.push(nums[i]);
                nums[i]=0;
            }
        }
        int i=0;
        while(!st.empty())
        {
            nums[i++]=st.top();
            st.pop();
        }
    }
};
