class Solution {
public:
    int minOperations(vector<int> &nums)
    {
        nums.push_back(0);
        vector<int> st;
        int n=nums.size(),count=0;
        for(int i=0;i<n;i++)
        {
            while(!st.empty())
            {
                if(nums[i]>st.back())
                {
                    st.push_back(nums[i]);
                    break;
                }
                else if(nums[i]<st.back())
                {
                    st.pop_back();
                    count++;
                }
                else
                {
                    break;
                }
            }
            if(st.empty() && nums[i]!=0)
            {
                st.push_back(nums[i]);
            }
        }
        return count;
    }
};
